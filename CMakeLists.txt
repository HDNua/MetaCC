set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-register")

project(metacc CXX)

cmake_minimum_required(VERSION 3.1)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(sv_parser
    sv_parser.yy
    ${CMAKE_CURRENT_BINARY_DIR}/sv_parser.tab.cc)

FLEX_TARGET(sv_lexer
    sv_lexer.l
    ${CMAKE_CURRENT_BINARY_DIR}/sv_lexer.yy.cc)

add_executable(metacc
    main.cpp
    ast_lyc_common.cpp
	ast_lyc_describe.cpp
	ast_lyc_glance.cpp
	ast_lyc_action.cpp
	#ast_lycpp_common.cpp
	#ast_lycpp_describe.cpp
	#ast_lycpp_glance.cpp
	#ast_lycpp_action.cpp
	#ast_javacc_common.cpp
	#ast_javacc_describe.cpp
	#ast_javacc_glance.cpp
	#ast_javacc_action.cpp

    ${FLEX_sv_lexer_OUTPUTS}
    ${BISON_sv_parser_OUTPUTS}
    )

target_include_directories(metacc
    PRIVATE
    .
    ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET metacc
    PROPERTY CXX_STANDARD 14)

enable_testing()
add_test(NAME basic
    COMMAND ${CMAKE_SOURCE_DIR}/test/test0.pl
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_BUILD_TYPE Debug)
