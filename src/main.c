#include <X11/Xlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <pthread.h>

#include "mouse_click.h"

#define DESIRED_CPS 10


void *xdotool_check_left_clicking(void *is_left_click_pressed) {
  while(1) {
    int *a = (int *)(is_left_click_pressed);
    if(*a == 1) {
      mouse_click(1);
    }

    usleep(1000000 / DESIRED_CPS);
  }
}


int main(int argc, char *argv[]) {
  int fd, bytes;
  unsigned char data[4];

  const char *pDevice = "/dev/input/mice";

  fd = open(pDevice, O_RDWR);
  if (fd == -1) {
    printf("ERROR Opening %s\n", pDevice);
    return -1;
  }


  int is_left_click_pressed = 0;

  pthread_t left_click_thread; 
  pthread_create(&left_click_thread, NULL, xdotool_check_left_clicking, (void *)&is_left_click_pressed);

  int left;

  while (1) {
    bytes = read(fd, data, sizeof(data));

    if (bytes > 0) {
      left = data[0] & 0x1;

      if (left)
	is_left_click_pressed = 1;
      else
        is_left_click_pressed = 0;
    }
  }
  return 0;
}
