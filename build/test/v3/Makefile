EXE=out
YACC_SRC=*.y
LEX_SRC=*.l
LINK=-lfl -lm
CC=cc



default: all_lyc

all_lyc: clean_lyc yacc lex cc

debug: debug_build test

debug_build: clean yacc_dbg lex_dbg cc_dbg

yacc:
	yacc -d $(YACC_SRC)

lex:
	lex $(LEX_SRC)

cc: 
	$(CC) -o $(EXE) *.c $(LINK)

yacc_dbg:
	yacc -g -d -v -t $(YACC_SRC)

lex_dbg:
	lex $(LEX_SRC)

cc_dbg: 
	$(CC) -DYYDEBUG -g -o $(EXE) *.c $(LINK) -DYYDEBUG 

test: test2
	echo "done."

test1:
	./$(EXE) < source.txt

test2:
	./$(EXE) < wrong.txt

clean: clean_lyc

clean_all: clean_pp clean

clean_pp:
	rm -rf parser.l.*
	rm -rf parser.y.*
	rm -rf parser_ast.c.*
	rm -rf parser_ast.h.*

clean_lyc:
	rmtmp
	rm -rf y.tab.c y.tab.h lex.yy.c
	rm -rf y.output y.dot
	rm -rf $(EXE)
	if [ -f out/Makefile ]; then \
		mv out/Makefile Makefile_out; \
		fi
	rm -rf out/*
	if [ -f Makefile_out ]; then \
		mv Makefile_out out/Makefile; \
		fi
