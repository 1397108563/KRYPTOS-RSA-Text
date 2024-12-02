program = g++
all:
	$(program) -o build/encoder encoder.cpp
	$(program) -o build/decoder decoder.cpp
	$(program) -o build/key key.cpp
clean:
	rm -rf build
