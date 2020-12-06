


default: all

all: clean gen_calc_parser run_calc_parser

gen_calc_parser:
	./gen_calc_parser.sh

run_calc_parser:
	./out/build/out < ./example/code1.x

clean:
	rm -rf ./out/parser.l  
	rm -rf ./out/parser.l.tokendef
	rm -rf ./out/parser.yy
	rm -rf ./out/parser.yy.list
	rm -rf ./out/parser.yy.opt
	rm -rf ./out/parser.yy.star
	rm -rf ./out/parser.yy.syntax
	rm -rf ./out/parser.yy.token
	rm -rf ./out/parser.yy.type
	rm -rf ./out/parser.yy.union
	rm -rf ./out/parser_ast.cpp
	rm -rf ./out/parser_ast.cpp.templates
	rm -rf ./out/parser_ast.h
	rm -rf ./out/parser_ast.h.declaration
	rm -rf ./out/parser_ast.h.typedef
	rm -rf ./out/build/*
