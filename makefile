# c set up
all_dir := $(shell python3 scan.py c)
cfiles := $(wildcard $(all_dir))
cobjs := $(patsubst %.c, %.out, $(cfiles))
cc = clang
cflags = -fopenmp -g -lpthread -lm


# cpp set up
all_dir := $(shell python3 scan.py cpp)
cppfiles := $(wildcard $(all_dir))
cppobjs += $(patsubst %.cpp, %.out, $(cppfiles))
cxx = clang++
cppflags = -fopenmp -g -lpthread -std=c++11

all: $(cobjs) $(cppobjs)

%.out: %.c 
	$(cc) $(cflags) $< -o $@

%.out: %.cpp
	$(cxx) $(cppflags) $< -o $@

.PHNOY: clean

clean:
	@rm $(cobjs) $(cppobjs)
