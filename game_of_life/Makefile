build/main.out: build/main.o build/cell.o build/grid.o build/conway.o
	g++ build/main.o build/cell.o build/grid.o build/conway.o -lncursesw -o build/main.out

build/cell.o: cell.cpp cell.h
	@mkdir -p build
	g++ cell.cpp -c -o build/cell.o

build/grid.o: grid.cpp grid.h cell.h
	@mkdir -p build
	g++ grid.cpp -c -o build/grid.o

build/conway.o: conway.cpp conway.h grid.h
	@mkdir -p build
	g++ conway.cpp -c -o build/conway.o

build/main.o: main.cpp conway.h 
	@mkdir -p build
	g++ main.cpp -c -o build/main.o

.PHONY: clean

clean:
	rm -rf build
