# samples-doc_transponders_unix / UNIX DOC sample codes for RFID transponders
This repository contains sample codes for handling both HF and UHF transponders on devices running UNIX OS using a Micro-Sensys RFID reader

> For details on DOC communication check [Useful Links](#Useful-Links) 

## Requirements
* IDE (eclipse IDE / CodeBlocks) or any source code editor
* Micro-Sensys RFID reader
* Any HF or UHF transponder

## Implementation
This code shows how to read/write transponders in UNIX systems. 
> The recommended way is to use the Java library available (See [Useful Links](#Useful-Links)). 
> If this is not possible, there are some samples available on how to communicate with our RFID readers using low level protocol. This protocol is only available on request. [Contact](#Contact) us with your requirements and we will try to support you.

## Steps
>> **TODO: in progress**

### Special Hints for Linux
* Device has to be configured in USB VCP mode (ask microsensys for HowTo)
	* To get VCP port name use:	
		> dmesg | grep FTDI
* To be able to communicate with RFID reader, the user must be part of the group "dialout".
	* To add the user to the group use:
		> sudo gpasswd --add [username] dialout

## Useful Links
* [JAR Library and API documentation](https://www.microsensys.de/downloads/DevSamples/Libraries/UNIX/microsensysRFID%20-%20jar%20library/)
* Check what is possible using our iID®DEMOsoft for PC! Download it using [this link](https://www.microsensys.de/downloads/CDContent/Install/iID%c2%ae%20DEMOsoft.zip)
* GitHub *doc* repository: [Micro-Sensys/doc](https://github.com/Micro-Sensys/doc)
	* [communication-modes/doc](https://github.com/Micro-Sensys/doc/tree/master/communication-modes/doc)

## Contact

* For coding questions or questions about this sample code, you can use [support@microsensys.de](mailto:support@microsensys.de)
* For general questions about the company or our devices, you can contact us using [info@microsensys.de](mailto:info@microsensys.de)

## Authors

* **Victor Garcia** - *Initial work* - [MICS-VGarcia](https://github.com/MICS-VGarcia/)
