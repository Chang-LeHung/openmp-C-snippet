# c set up
all_dir := $(shell python3 scan.py c)
cfiles := $(wildcard $(all_dir))
cobjs := $(patsubst %.c, %.out, $(cfiles))
cc = clang
cflags = -fopenmp -g


# cpp set up
all_dir := $(shell python3 scan.py cpp)
cppfiles := $(wildcard $(all_dir))
cppobjs += $(patsubst %.cpp, %.out, $(cppfiles))
cxx = clang++
cflags = -fopenmp -g

all: $(cobjs) $(cppobjs)

%.out: %.c 
	$(cc) $(cflags) $< -o $@

%.out: %.cpp
	$(cxx) $(cflags) $< -o $@

.PHNOY: clean

clean:
	@rm $(cobjs) $(cppobjs)
