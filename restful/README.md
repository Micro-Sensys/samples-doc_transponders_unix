# RESTful DOC sample code for RFID transponders
Here you can find different samples for handling both HF and UHF transponders on devices running UNIX OS using a Micro-Sensys RFID reader.
Sample codes located in this folder are implemented accessing our *iID®service* (using RESTful communicating) 

> For details on DOC communication check [Useful Links](#Useful-Links) 


## Requirements
* IDE (for example Visual Studio Code)
* Micro-Sensys RFID reader (either Bluetooth or module)
* Any HF or UHF transponder

## Implementation
This code shows how to use **iID®service** and its RESTful API to read/write transponders. 
For demo purposes, a python console sample code and a HTML website with JavaScript code is provided. There are different projects available that show all the different functions provided.

> Class information is available under API documentation. See [Useful Links](#Useful-Links)

## Steps 
### Python console
 1. Import this project into your IDE. 
 2. First make sure the communication port name for the RFID reader (for example */dev/ttyUSB0*) is selected. 
 3. Then use the console *menu* to select the function to call

### JavaScript (+HTML)
 1. First make sure the communication port name for the RFID reader (for example */dev/ttyUSB0*) is selected using *interface.html*
 2. Open any other HTML files and select the function to call

### Special Hints for Linux
* Device has to be configured in USB VCP mode (ask microsensys for HowTo)
	* To get VCP port name use:	
		> dmesg | grep FTDI
* To be able to communicate with RFID reader, the user must be part of the group "dialout".
	* To add the user to the group use:
		> sudo gpasswd --add [username] dialout

## Useful Links
* [API documentation](https://www.microsensys.de/downloads/DevSamples/Libraries/UNIX/iIDservice%20-%20RESTful/APIDoc_iIDservice_1.3_E.pdf)
* Check what is possible using our iID®DEMOsoft for PC! Download it using [this link](https://www.microsensys.de/downloads/CDContent/Install/iID%c2%ae%20DEMOsoft.zip)
* GitHub *documentation* repository: [Micro-Sensys/documentation](https://github.com/Micro-Sensys/documentation)
	* [communication-modes/doc](https://github.com/Micro-Sensys/documentation/tree/master/communication-modes/doc)

## Contact

* For coding questions or questions about this sample code, you can use [support@microsensys.de](mailto:support@microsensys.de)
* For general questions about the company or our devices, you can contact us using [info@microsensys.de](mailto:info@microsensys.de)

## Authors

* **Victor Garcia** - *Initial work* - [MICS-VGarcia](https://github.com/MICS-VGarcia/)