# XAutoClicker

A suckless x11 mouse autoclicker

## Getting Started 
```console
$ git clone https://github.com/GuimilXD/xautoclicker
$ cd xautoclicker
$ make
$ sudo ./xautoclicker
```

DISCLAIMER: This program requires access to the `/dev/input/mice` device file. Running the program with `sudo` should do the trick.

## Configuration

You can change the default CPS (Clicks Per Second) by editing `src/main`:
```c
#define DESIRED_CPS 10
```
