CC=gcc
CFLAGS=-c -Wall -lmraa

all: pwm

pwm: pwm.o
	$(CC) pwm.o -o pwm
