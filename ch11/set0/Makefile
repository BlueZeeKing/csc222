build/test.out: build/test_fraction.o build/Fraction.o
	g++ build/test_fraction.o build/Fraction.o -std=c++23 -o build/test.out

build/main.out: build/main.o build/Time.o
	g++ build/main.o build/Time.o -std=c++23 -o build/main.out

build/exercise0.out: build/exercise0.o build/Time.o
	g++ build/exercise0.o build/Time.o -std=c++23 -o build/exercise0.out

build/Time.o: Time.cpp Time.h
	@mkdir -p build
	g++ Time.cpp -c -o build/Time.o -std=c++23

build/Fraction.o: Fraction.cpp Fraction.h
	@mkdir -p build
	g++ Fraction.cpp -c -o build/Fraction.o -std=c++23

build/exercise0.o: exercise0.cpp Time.h
	@mkdir -p build
	g++ exercise0.cpp -c -o build/exercise0.o -std=c++23

build/main.o: main.cpp Time.h
	@mkdir -p build
	g++ main.cpp -c -o build/main.o -std=c++23

build/test_fraction.o: test_fraction.cpp Fraction.h
	@mkdir -p build
	g++ test_fraction.cpp -c -o build/test_fraction.o -std=c++23

.PHONY: clean test all

clean:
	rm -rf build

test: build/test.out
	./build/test.out

all: build/test.out build/main.out build/exercise0.out
