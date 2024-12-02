program = g++
all:
	mkdir -p build
	$(program) -I./include/ -o build/encoder encoder.cpp
	$(program) -I./include/ -o build/decoder decoder.cpp
	$(program) -I./include/ -o build/key key.cpp
clean:
	rm -rf build
