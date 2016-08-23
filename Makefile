CC=gcc
CFLAGS=-c -Wall -lmraa

all: pwm

pwm: examples/pwm.o
	$(CC) examples/pwm.o -o pwm
