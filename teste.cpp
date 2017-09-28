#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
int fd=serialOpen("/dev/ttyUSB0",9600);
int i=0;
char ch[1000];
int datalength=0;

if(fd)
{
printf("Connected \n");

while(1)
{
	
	datalength=serialDataAvail(fd);
	if(datalength!=-1)
	{
		while(datalength>0){	
			ch[i]=serialGetchar(fd);
			datalength--;
			i++;
			}
			ch[i]='\0';
			i=0;
			printf("Data: %s \n",ch);

	}
	delay(2000);
	}

}
else printf("Not connected.");

serialClose(fd);
return 0;
}
