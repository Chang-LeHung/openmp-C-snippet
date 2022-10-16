
VPATH=src:./sub
# cfiles = $(wildcard *.c sub/*.c)
cfiles = $(wildcard *.c)

cobjs = $(patsubst %.c, %.out, $(cfiles))
cc = gcc
cflags = -fopenmp -g
all: $(cobjs) world

%.out: %.c 
	$(cc) $(cflags) $< -o $@

world: world.c
	$(cc) $(cflags) $< -o $@

.PHNOY: clean

clean:
	rm $(cobjs) world
