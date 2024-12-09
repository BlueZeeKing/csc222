CC=g++
STD=c++23

build/%.o: %.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_cards: build/test_cards.o build/Card.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test all clean

test: build/test_cards
	./build/test_cards

all: build/test_cards

clean:
	rm -rf build
