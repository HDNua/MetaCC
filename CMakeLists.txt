set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-register")

project(metacc CXX)

cmake_minimum_required(VERSION 3.1)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(mcc_parser
    mcc_parser.yy
    ${CMAKE_CURRENT_BINARY_DIR}/mcc_parser.tab.cc)

FLEX_TARGET(mcc_lexer
    mcc_lexer.l
    ${CMAKE_CURRENT_BINARY_DIR}/mcc_parser.yy.cc)

add_executable(metacc
    main.cpp
	ast_common.cpp
	ast_describe.cpp
	ast_glance.cpp
	ast_action.cpp

    ${FLEX_mcc_lexer_OUTPUTS}
    ${BISON_mcc_parser_OUTPUTS}
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
