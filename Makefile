EXE=out
YACC_SRC=*.y
LEX_SRC=*.l
LINK=-lfl -lm
CC=cc

default: all

all: clean yacc lex cc

debug: debug_build test

debug_build: clean yacc_dbg lex_dbg cc_dbg

yacc:
	yacc -d $(YACC_SRC)

lex:
	lex $(LEX_SRC)

cc: 
	$(CC) -o $(EXE) *.c $(LINK)

yacc_dbg:
	yacc -gdvt $(YACC_SRC)

lex_dbg:
	lex $(LEX_SRC)

cc_dbg: 
	$(CC) -g -o $(EXE) *.c $(LINK) -DYYDEBUG 

test:
	./$(EXE) < symbols.list

clean:
	rmtmp
	rm -rf y.tab.c y.tab.h lex.yy.c
	rm -rf y.output y.dot
	rm -rf $(EXE)
