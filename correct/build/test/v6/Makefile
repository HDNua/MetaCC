EXE=out
YACC_SRC=*.y
LEX_SRC=*.l
LINK=-lfl -lm
CC=cc
TARGET1=source.txt
TARGET2=wrong.txt
TARGET_SV=source.sv



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
	yacc -d -v -t $(YACC_SRC)

lex_dbg:
	lex $(LEX_SRC)

cc_dbg: 
	$(CC) -DYYDEBUG -g -o $(EXE) *.c $(LINK) -DYYDEBUG 

test: test1
	echo "done."

test1:
	./$(EXE) < $(TARGET1)

test2:
	./$(EXE) < $(TARGET2)

sv: clean_all all_lyc
	./$(EXE) < $(TARGET_SV)

sv_dbg: clean_all debug_build
	./$(EXE) < $(TARGET_SV)

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
