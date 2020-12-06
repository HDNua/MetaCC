EXE=out
SRC=*.cpp
LIBS=
CC=g++

all:
	$(CC) -g -o $(EXE) -std=c++11 $(SRC) $(LIBS)

clean:
	rm -rf $(EXE) *.o *~ *.swp

test:
	./$(EXE) < input.txt > output.txt

check:
	diff -q answer.txt output.txt
