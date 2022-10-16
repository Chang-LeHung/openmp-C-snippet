

cfiles = $(wildcard *.c)
cobjs = $(patsubst %.c, %.out, $(cfiles))
cc = gcc
cflags = -fopenmp -g
all: $(cobjs)

%.out: %.c 
	$(cc) $(cflags) $< -o $@
.PHNOY: clean

# clean:
# 	rm $(cobjs)
