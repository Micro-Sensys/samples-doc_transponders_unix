#ifndef PORTCONNECTION_H
#define PORTCONNECTION_H

#include <stdio.h>
#include <chrono>
#include <fcntl.h>      /* File Control Definitions */
#include <termios.h>    /* POSIX Terminal Control Definitions */
#include <unistd.h>     /* UNIX Standard Definitions usleep*/
#include <sys/ioctl.h>  /* ioctl() */

class PortConnection
{
    public:
        PortConnection();
        virtual ~PortConnection();

        bool   OpenPort(const char* _pPort);
        bool   ClosePort();
        int    CheckBytesInBuffer();
        void   ClearReceiveBuffer();
        int    WriteBytesToPort(const unsigned char* _pBytes, int _numberBytes);
        int    ReadBytesFromPort(unsigned char& _pBytes, int _numberBytes);

    protected:

    private:
        int    m_PortHandle;
        bool   SetPortSettings(int _handle);
        void    WaitForData(int _handle, int _timeoutMs, int _minDataCount);
};

#endif // PORTCONNECTION_H
