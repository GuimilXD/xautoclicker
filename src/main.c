#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
  int fd, bytes;
unsigned char data[4];

const char *pDevice = "/dev/input/mice";

fd = open(pDevice, O_RDWR);
if(fd == -1)
{
    printf("ERROR Opening %s\n", pDevice);
    return -1;
}

int left, middle, right;
signed char x, y;

// Read Mouse
while(1) {
bytes = read(fd, data, sizeof(data));

if(bytes > 0)
{
    left = data[0] & 0x1;
    right = data[0] & 0x2;
    middle = data[0] & 0x4;

    printf("left=%d, middle=%d, right=%d\n", left, middle, right);
   }
}
 return 0;
}
