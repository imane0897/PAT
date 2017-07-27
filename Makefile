FILE = 1004

all: clean

build:
	g++ -std=c++11 $(FILE).cpp -o $(FILE).out

run: build
	./$(FILE).out < INPUT

clean: run
	rm -f $(FILE).o $(FILE).out
