
cfiles += $(wildcard *.c flush/*.c task/*.c group/*c)
cobjs += $(patsubst %.c, %.out, $(cfiles))
cc = clang
cflags = -fopenmp -g
all: $(cobjs)

%.out: %.c 
	$(cc) $(cflags) $< -o $@
.PHNOY: clean a

clean:
	@rm $(cobjs)
