#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DEVICE_FILE "/dev/random_dev"

int main() {
	int ret, random;
	int fd = -1;
    	char option;

    	printf("Select below options:\n");
    	printf("\to (to open)\n");
	printf("\tr (to read a random number)\n");	
    	printf("\tc (to close the device)\n");
  
    	while (1) {
        	printf("Enter your option: ");
        	scanf("%c", &option);
		while ((getchar()) != '\n');

        	switch (option) {

            	case 'o':
			if (fd >= 0) 
				printf("=> Device has already opened !!\n");						
			else { 
				fd = open(DEVICE_FILE, 0);
				if (fd < 0) {
					printf("=> Cannot open device %s !!\n", DEVICE_FILE);
					return errno;
				}
			}        			
			break;	
				                 
	    	case 'r':
			if (fd < 0)
				printf("=> Device has not opened yet !!\n");
			else {
				ret = read(fd, &random, sizeof(random));
				printf("=> Random number: %d\n", ret);
			}
			break;

		case 'c':               
                	close(fd);                
                	printf("=> Close random device successfully\n");
                	return 0;
	 
            	default:
                	printf("=> Invalid option %c\n", option);
                	break;
        	}
	}
}
