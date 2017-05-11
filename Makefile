FILE = demo

all: clean

build:
	g++ $(FILE).cpp -o $(FILE).out

run: build
	./$(FILE).out < INPUT

clean: run
	rm -f $(FILE).o $(FILE).out
