CC=g++
STD=c++23

build/%.o: %.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_fraction: build/test_fraction.o Fraction.o
	$(CC) -o $@ $^ -std=$(STD)

build/main: build/main.o Time.o
	$(CC) -o $@ $^ -std=$(STD)

build/exercise0: build/exercise0.o Time.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test all clean

test: build/test_fraction
	./build/test_fraction

all: build/test_fraction build/exercise0 build/main

clean:
	rm -rf build
