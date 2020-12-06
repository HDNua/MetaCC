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
	yacc -gdvt $(YACC_SRC)

lex_dbg:
	lex $(LEX_SRC)

cc_dbg: 
	$(CC) -g -o $(EXE) *.c $(LINK) -DYYDEBUG 

test: test2

test_dep:
	./$(EXE) < symbols.list > SVObject.jj
	javacc SVObject.jj
	javac *.java
	mv SVObject.jj out
	mv *.java out
	mv *.class out 

test1:
	./$(EXE) javacc < symbols.list

test2:
	./$(EXE) lyc < symbols.list

clean: clean_lyc

clean_lyc:
	rmtmp
	rm -rf *.java
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



all_javacc: clean_javacc
	javacc *.jj
	javac *.java
	java SVParser

clean_javacc:
	rm -rf *.class
	mv SVObject.java SVObject.java_
	rm -rf *.java
	mv SVObject.java_ SVObject.java
