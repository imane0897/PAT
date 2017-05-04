FILE = 1009

all: clean

build:
	g++ -Wall $(FILE).cpp -o $(FILE).out

run: build
	./$(FILE).out < INPUT

clean: run
	rm -f $(FILE).o $(FILE).out
