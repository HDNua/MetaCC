set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set (CMAKE_CXX_STANDARD 11)

project(out CXX)

cmake_minimum_required(VERSION 3.1)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(parser
    parser.yy
    ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cc)

FLEX_TARGET(lexer
    parser.l
    ${CMAKE_CURRENT_BINARY_DIR}/parser.yy.cc)

add_executable(out
    parser_ast.cpp

    ${BISON_parser_OUTPUTS}
    ${FLEX_lexer_OUTPUTS}
    )

target_include_directories(out
    PRIVATE
    .
    ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET out
    PROPERTY CXX_STANDARD 14)

enable_testing()
add_test(NAME basic
    COMMAND ${CMAKE_SOURCE_DIR}/test/test0.pl
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_BUILD_TYPE Debug)

add_custom_target(debug
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND bison -t -v *.yy
	COMMAND flex *.l
	COMMAND g++ -g -DYYDEBUG=1 -o out *.cpp *.cc
	) 
add_custom_target(clean_all
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND rm -rf *.tab.*
	COMMAND rm -rf *.output *.dot
	COMMAND rm -rf parser.l.* parser.yy.* parser_ast.h.* parser_ast.cpp.*
	COMMAND rm -rf $(EXE)
	)
add_custom_target(init
	COMMAND make clean_all
	COMMAND make
	)
