#include "PortConnection.h"

PortConnection::PortConnection()
{
    //ctor
    m_PortHandle = -1;
}

PortConnection::~PortConnection()
{
    //dtor
}

bool PortConnection::OpenPort(const char* _pPort)
{
    this->m_PortHandle = open(_pPort, O_RDWR | O_NDELAY | O_SYNC);
    if (this->m_PortHandle == -1)
        return false;
    else
        return SetPortSettings(m_PortHandle);
}

bool PortConnection::SetPortSettings(int _handle)
{
    struct termios SerialPortSettings;

    tcgetattr(_handle, &SerialPortSettings); //Get current Port Settings
    cfsetspeed(&SerialPortSettings, B57600); //Set Baudrate
    SerialPortSettings.c_cflag &= ~PARENB; //No Parity
    SerialPortSettings.c_cflag &= ~CSTOPB; //Stop bits = 1
    SerialPortSettings.c_cflag &= ~CSIZE; //Clear the Mask
    SerialPortSettings.c_cflag |= CS8; //Set the data bits = 8
    SerialPortSettings.c_cflag &= ~CRTSCTS; //No hardware flow control (RTS CTS)
    SerialPortSettings.c_cflag |= CREAD | CLOCAL; //enable receiver to reading from serial port
    cfmakeraw(&SerialPortSettings); /* sets the terminal to something like the "raw" mode of the old Version 7 terminal driver */

    int set_info = tcsetattr(_handle, TCSANOW,&SerialPortSettings); //Set new Port Settings

    if (set_info != 0)
        return false;
    return true;

    //TODO: Clear DTR + wait 200ms!?
    /*Set DTR Flag*/
    int DTR_flag = TIOCM_DTR;

    ioctl(_handle, TIOCMBIS,&DTR_flag);

	return true;
}

bool    PortConnection::ClosePort()
{
    if (m_PortHandle != -1)
    {
        //TODO: clear DTR!
        close(m_PortHandle);
    }
    m_PortHandle = -1;
    return true;
}

int     PortConnection::CheckBytesInBuffer()
{
    int available = 0;
    ioctl(m_PortHandle,FIONREAD, &available); //read number of received bytes
    return available;
}

void    PortConnection::ClearReceiveBuffer()
{
    //clear read and write buffer
    tcflush(m_PortHandle, TCIOFLUSH); //TCIFLUSH - flushes data received but not read, TCOFLUSH - flushes data written but not transmitted

    unsigned char dummy[1] = {0};
    while(CheckBytesInBuffer() > 0)
    {
        ReadBytesFromPort(*dummy, 1);
    }
}

int     PortConnection::WriteBytesToPort(const unsigned char* _pBytes, int _Length)
{
    int numWritten = write(m_PortHandle, _pBytes, _Length);
    if (numWritten > 0)
        tcdrain(m_PortHandle); //waits until all output written to the object referred to by m_Port has been transmitted.
    return numWritten;
}

int     PortConnection::ReadBytesFromPort(unsigned char& _pBytes, int _Length)
{
    WaitForData(m_PortHandle, 60, _Length);
    int numRead = read(m_PortHandle, &_pBytes, _Length);
    return numRead;
}

void    PortConnection::WaitForData(int _handle, int _timeoutMs, int _minDataCount)
{
    if ((_minDataCount == 0) || (_timeoutMs == 0))
        return;

    std::chrono::steady_clock::time_point startTimeWait = std::chrono::steady_clock::now();
    while (
        (CheckBytesInBuffer() < _minDataCount) &&
        (std::chrono::steady_clock::now() <= (startTimeWait - std::chrono::milliseconds(_timeoutMs))))
    {
        usleep(5000); //5000 microseconds
    }
}
