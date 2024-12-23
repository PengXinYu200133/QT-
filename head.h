#ifndef __HEAD_H
#define __HEAD_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <linux/input.h>




void mmap_show_bmp(char *name);
void key_ctrl(int *x,int *y);

#endif
