program = g++

all:
ifeq ($(shell uname), Linux)
		mkdir -p build
		$(program) -I./include/ -o build/encoder unix/encoder.cpp
		$(program) -I./include/ -o build/decoder unix/decoder.cpp
		$(program) -I./include/ -o build/key unix/key.cpp
endif
clean:
	rm -rf build
