CC=g++
STD=c++23

build/test_times: build/test_times.o build/Time.o
	$(CC) -o $@ $^ -std=$(STD)

build/test_points: build/test_points.o build/Point.o
	$(CC) -o $@ $^ -std=$(STD)

build/hand_test: build/hand_test_times.o build/Time.o
	$(CC) -o $@ $^ -std=$(STD)

build/%.o: %.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

-include build/*.d

.PHONY: clean test all

clean:
	rm -rf build

test: build/test_times build/test_points
	./build/test_times
	./build/test_points

all: build/test_times build/hand_test build/test_points
