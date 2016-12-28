Project 3: ECEN 5013 {Embedded Software Essentials}
Group Members: 1. Arundhathi Swami
		   2. Vignesh Jayaram
This project comprises of 3 modules:
MODULE 1:
In module 1, we implemented memmove and memzero functions using DMA and measured time taken for the same using code profiling. DMA registers were configured for transfer of bytes and words. A comparison was made between time taken by DMA and time taken by standard library functions for memove and memzero.
MODULE 2:
In module 2, we were required to design a message interface to transfer commands between two devices. The transmitting device was serial monitor of the local host machine and FRDM KL25Z board was the receiver. The message packet structure comprised of 4 members namely: command, length, data and checksum. Using the message packet, the onboard led of FRDM board was controlled i.e to toggle colors and vary their brightness.
The command ID i.e. the first structure member comprises of different colors. These colors are defined in an enumeration. The command IDs for different colors are: 
	COLOR_RED = 0x01,
	COLOR_BLUE = 0x02,
	COLOR_GREEN = 0x03,
	COLOR_YELLOW = 0x04,
	COLOR_MAGENTA = 0x05,
	COLOR_CYAN = 0x06,
	COLOR_WHITE = 0x07

There are two functions defined in this module basically to read the message packet sent and to decode it. Based on the message received, the corresponding color was lit and its brightness was set.
MODULE 3:
In module 3, for FRDMKL25Z board libraries were written for both SPI and NRF. The basic function of these libraries is to initialize SPI so that reads and write functions can be performed on the registers of nRF24L01+. Whereas for BeagleBoneBlack, predefined driver libraries were used to read and write to the registers of Nordic chip.   





