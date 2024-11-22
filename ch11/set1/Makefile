build/test.out: build/test_times.o build/Time.o
	g++ build/test_times.o build/Time.o -std=c++23 -o build/test.out

build/hand_test.out: build/hand_test.o build/Time.o
	g++ build/hand_test.o build/Time.o -std=c++23 -o build/hand_test.out

build/test_times.o: test_times.cpp Time.h
	@mkdir -p build
	g++ test_times.cpp -c -o build/test_times.o -std=c++23

build/Time.o: Time.cpp Time.h
	@mkdir -p build
	g++ Time.cpp -c -o build/Time.o -std=c++23

build/hand_test.o: hand_test_times.cpp Time.h 
	@mkdir -p build
	g++ hand_test_times.cpp -c -o build/hand_test.o -std=c++23

.PHONY: clean test all

clean:
	rm -rf build

test: build/test.out
	./build/test.out

all: build/test.out build/hand_test.out
