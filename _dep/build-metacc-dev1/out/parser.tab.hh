/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_HANDY_DROPBOX_LINUX_WORK_YACC_METACC_LATEST_BUILD_OUT_PARSER_TAB_HH_INCLUDED
# define YY_YY_HOME_HANDY_DROPBOX_LINUX_WORK_YACC_METACC_LATEST_BUILD_OUT_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    LIBRARY_ = 259,
    COMMA = 260,
    DASH_INCDIR_ = 261,
    INCLUDE_ = 262,
    ENDMODULE_ = 263,
    COLON = 264,
    EXTERN_ = 265,
    MODULE_ = 266,
    MACROMODULE_ = 267,
    ENDINTERFACE_ = 268,
    INTERFACE_ = 269,
    LP = 270,
    DOT_STAR = 271,
    RP = 272,
    ENDPROGRAM_ = 273,
    PROGRAM_ = 274,
    CHECKER_ = 275,
    ENDCHECKER_ = 276,
    VIRTUAL_ = 277,
    CLASS_ = 278,
    EXTENDS_ = 279,
    IMPLEMENTS_ = 280,
    ENDCLASS_ = 281,
    PACKAGE_ = 282,
    ENDPACKAGE_ = 283,
    TIMEUNIT_ = 284,
    SLASH = 285,
    TIMEPRECISION_ = 286,
    SHARP = 287,
    TYPE_ = 288,
    DOT = 289,
    LMP = 290,
    RMP = 291,
    INPUT_ = 292,
    OUTPUT_ = 293,
    INOUT_ = 294,
    REF_ = 295,
    EQ = 296,
    DOLLAR_FATAL_ = 297,
    DOLLAR_ERROR_ = 298,
    DOLLAR_WARNING_ = 299,
    DOLLAR_INFO_ = 300,
    ZERO_ = 301,
    ONE_ = 302,
    TWO_ = 303,
    DEFAULT_ = 304,
    CLOCKING_ = 305,
    DISABLE_ = 306,
    IFF_ = 307,
    DEFPARAM_ = 308,
    BIND_ = 309,
    CONFIG_ = 310,
    ENDCONFIG_ = 311,
    DESIGN_ = 312,
    INSTANCE_ = 313,
    CELL_ = 314,
    LIBLIST_ = 315,
    USE_ = 316,
    FORKJOIN_ = 317,
    RAND_ = 318,
    CONST_ = 319,
    PURE_ = 320,
    FUNCTION_ = 321,
    NEW_ = 322,
    STATIC_ = 323,
    PROTECTED_ = 324,
    LOCAL_ = 325,
    RANDC_ = 326,
    SUPER_ = 327,
    ENDFUNCTION_ = 328,
    CONSTRAINT_ = 329,
    SOLVE_ = 330,
    BEFORE_ = 331,
    SOFT_ = 332,
    RIGHTARROW = 333,
    IF_ = 334,
    ELSE_ = 335,
    FOREACH_ = 336,
    LSP = 337,
    RSP = 338,
    UNIQUE_ = 339,
    COLON_EQUAL = 340,
    COLON_SLASH = 341,
    LOCALPARAM_ = 342,
    PARAMETER_ = 343,
    SPECPARAM_ = 344,
    VAR_ = 345,
    IMPORT_ = 346,
    COLON2 = 347,
    STAR = 348,
    EXPORT_ = 349,
    STAR_COLON2_STAR = 350,
    GENVAR_ = 351,
    VECTORED_ = 352,
    SCALARED_ = 353,
    INTERCONNECT_ = 354,
    TYPEDEF_ = 355,
    ENUM_ = 356,
    STRUCT_ = 357,
    UNION_ = 358,
    NETTYPE_ = 359,
    WITH_ = 360,
    AUTOMATIC_ = 361,
    STRING_ = 362,
    PACKED_ = 363,
    CHANDLE_ = 364,
    EVENT_ = 365,
    BYTE_ = 366,
    SHORTINT_ = 367,
    INT_ = 368,
    LONGINT_ = 369,
    INTEGER_ = 370,
    TIME_ = 371,
    BIT_ = 372,
    LOGIC_ = 373,
    REG_ = 374,
    SHORTREAL_ = 375,
    REAL_ = 376,
    REALTIME_ = 377,
    SUPPLY0_ = 378,
    SUPPLY1_ = 379,
    TRI_ = 380,
    TRIAND_ = 381,
    TRIOR_ = 382,
    TRIREG_ = 383,
    TRI0_ = 384,
    TRI1_ = 385,
    UWIRE_ = 386,
    WIRE_ = 387,
    WAND_ = 388,
    WOR_ = 389,
    SIGNED_ = 390,
    UNSIGNED_ = 391,
    VOID_ = 392,
    TAGGED_ = 393,
    HIGHZ1_ = 394,
    HIGHZ0_ = 395,
    STRONG0_ = 396,
    PULL0_ = 397,
    WEAK0_ = 398,
    STRONG1_ = 399,
    PULL1_ = 400,
    WEAK1_ = 401,
    SMALL_ = 402,
    MEDIUM_ = 403,
    LARGE_ = 404,
    ONESTEP_ = 405,
    DOLLAR_ = 406,
    TASK_ = 407,
    DPI_C_ = 408,
    DPI_ = 409,
    CONTEXT_ = 410,
    ENDTASK_ = 411,
    PLUS = 412,
    PLUS2 = 413,
    MINUS = 414,
    MINUS2 = 415,
    STAR2 = 416,
    PERCENT = 417,
    EQ2 = 418,
    NEQ = 419,
    LT = 420,
    LTE = 421,
    GT = 422,
    GTE = 423,
    MODPORT_ = 424,
    ASSERT_ = 425,
    PROPERTY_ = 426,
    ASSUME_ = 427,
    COVER_ = 428,
    EXPECT_ = 429,
    SEQUENCE_ = 430,
    RESTRICT_ = 431,
    ENDPROPERTY_ = 432,
    STRONG_ = 433,
    WEAK_ = 434,
    NOT_ = 435,
    OR_ = 436,
    AND_ = 437,
    BAR_DASH_GT = 438,
    BAR_EQ_GT = 439,
    CASE_ = 440,
    ENDCASE_ = 441,
    SHARP_DASH_SHARP = 442,
    SHARP_EQ_SHARP = 443,
    NEXTTIME_ = 444,
    S_NEXTTIME_ = 445,
    ALWAYS_ = 446,
    S_ALWAYS_ = 447,
    S_EVENTUALLY_ = 448,
    UNTIL_ = 449,
    S_UNTIL_ = 450,
    UNTIL_WITH_ = 451,
    S_UNTIL_WITH_ = 452,
    IMPLIES_ = 453,
    ACCEPT_ON_ = 454,
    REJECT_ON_ = 455,
    SYNC_ACCEPT_ON_ = 456,
    SYNC_REJECT_ON_ = 457,
    ENDSEQUENCE_ = 458,
    UNTYPED_ = 459,
    INTERSECT_ = 460,
    FIRST_MATCH_ = 461,
    THROUGHOUT_ = 462,
    WITHIN_ = 463,
    SHARP2 = 464,
    LSP_STAR_RSP = 465,
    LSP_PLUS_RSP = 466,
    LSP_STAR = 467,
    LSP_EQ = 468,
    LSP_DASH_GT = 469,
    DIST_ = 470,
    LET_ = 471,
    COVERGROUP_ = 472,
    ENDGROUP_ = 473,
    OPTION_ = 474,
    TYPE_OPTION_ = 475,
    SAMPLE_ = 476,
    AT2 = 477,
    BEGIN_ = 478,
    END_ = 479,
    COVERPOINT_ = 480,
    WILDCARD_ = 481,
    BINS_ = 482,
    ILLEGRAL_BINS_ = 483,
    IGNORE_BINS_ = 484,
    EQ_GT = 485,
    CROSS_ = 486,
    NOT = 487,
    AND2 = 488,
    BAR2 = 489,
    MATCHES_ = 490,
    BINSOF_ = 491,
    PULLDOWN_ = 492,
    PULLUP_ = 493,
    CMOS_ = 494,
    RCMOS_ = 495,
    BUFIF0_ = 496,
    BUFIF1_ = 497,
    NOTIF0_ = 498,
    NOTIF1_ = 499,
    NMOS_ = 500,
    PMOS_ = 501,
    RNMOS_ = 502,
    RPMOS_ = 503,
    NAND_ = 504,
    NOR_ = 505,
    XOR_ = 506,
    XNOR_ = 507,
    BUF_ = 508,
    TRANIF0_ = 509,
    TRANIF1_ = 510,
    RTRANIF0_ = 511,
    RTRANIF1_ = 512,
    TRAN_ = 513,
    RTRAN_ = 514,
    GENERATE_ = 515,
    ENDGENERATE_ = 516,
    FOR_ = 517,
    PRIMITIVE_ = 518,
    ENDPRIMITIVE_ = 519,
    TABLE_ = 520,
    ENDTABLE_ = 521,
    INITIAL_ = 522,
    ONEBIT_GND = 523,
    ONEBIT_VDD = 524,
    ONEBIT_X0 = 525,
    ONEBIT_X1 = 526,
    ONEBIT_BGND = 527,
    ONEBIT_BVDD = 528,
    ONEBIT_BX0 = 529,
    ONEBIT_BX1 = 530,
    LETTER_X0_ = 531,
    LETTER_X1_ = 532,
    QMARK = 533,
    LETTER_B0_ = 534,
    LETTER_B1_ = 535,
    LETTER_R0_ = 536,
    LETTER_R1_ = 537,
    LETTER_F0_ = 538,
    LETTER_F1_ = 539,
    LETTER_P0_ = 540,
    LETTER_P1_ = 541,
    LETTER_N0_ = 542,
    LETTER_N1_ = 543,
    ASSIGN_ = 544,
    ALIAS_ = 545,
    ALWAYS_COMB_ = 546,
    ALWAYS_LATCH_ = 547,
    ALWAYS_FF_ = 548,
    FINAL_ = 549,
    PLUS_EQ = 550,
    MINUS_EQ = 551,
    STAR_EQ = 552,
    SLASH_EQ = 553,
    PERCENT_EQ = 554,
    AND_EQ = 555,
    BAR_EQ = 556,
    XOR_EQ = 557,
    LSHIFT_EQ = 558,
    RSHIFT_EQ = 559,
    LSHIFT2_EQ = 560,
    RSHIFT2_EQ = 561,
    DEASSIGN_ = 562,
    FORCE_ = 563,
    RELEASE_ = 564,
    FORK_ = 565,
    JOIN_ = 566,
    JOIN_ANY_ = 567,
    JOIN_NONE_ = 568,
    REPEAT_ = 569,
    AT = 570,
    RETURN_ = 571,
    BREAK_ = 572,
    CONTINUE_ = 573,
    WAIT_ = 574,
    WAIT_ORDER_ = 575,
    DASH_RSHIFT = 576,
    UNIQUE0_ = 577,
    PRIORITY_ = 578,
    AND3 = 579,
    INSIDE_ = 580,
    CASEX_ = 581,
    CASEZ_ = 582,
    RANDCASE_ = 583,
    APOSTROPHE = 584,
    FOREVER_ = 585,
    WHILE_ = 586,
    DO_ = 587,
    SHARP0_ = 588,
    ENDCLOCKING_ = 589,
    GLOBAL_ = 590,
    RANDSEQUENCE_ = 591,
    BAR_ = 592,
    SPECIFY_ = 593,
    ENDSPECIFY_ = 594,
    PULSESTYLE_ONEVENT_ = 595,
    PULSESTYPE_ONDETECT_ = 596,
    SHOWCANCELLED_ = 597,
    NOSHOWCANCELLED_ = 598,
    STAR_RT = 599,
    POSEDGE_ = 600,
    NEGEDGE_ = 601,
    EDGE_ = 602,
    IFNONE_ = 603,
    DOLLAR_SETUP_ = 604,
    DOLLAR_HOLD_ = 605,
    DOLLAR_SETUPHOLD_ = 606,
    DOLLAR_RECOVERY_ = 607,
    DOLLAR_REMOVAL_ = 608,
    DOLLAR_RECREM_ = 609,
    DOLLAR_SKEW_ = 610,
    DOLLAR_TIMESKEW_ = 611,
    DOLLAR_FULLSKEW_ = 612,
    DOLLAR_PERIOD_ = 613,
    DOLLAR_WIDTH_ = 614,
    DOLLAR_NOCHANGE_ = 615,
    ZERO_ONE = 616,
    ONE_ZERO = 617,
    LETTER_Z0_ = 618,
    LETTER_Z1_ = 619,
    WAVE = 620,
    EQ3 = 621,
    NEQ2 = 622,
    APOSTROPHE_B0_GND = 623,
    APOSTROPHE_B0_VDD = 624,
    APOSTROPHE_B1_GND = 625,
    APOSTROPHE_B1_VDD = 626,
    RSHIFT = 627,
    LSHIFT = 628,
    PLUS_COLON = 629,
    MINUS_COLON = 630,
    STD_COLON2 = 631,
    RANDOMIZE_ = 632,
    NULL_ = 633,
    THIS_ = 634,
    LOCAL_COLON2 = 635,
    LETTER_S0_ = 636,
    MS_ = 637,
    US_ = 638,
    NS_ = 639,
    PS_ = 640,
    FS_ = 641,
    AND = 642,
    WAVE_AND = 643,
    WAVE_BAR = 644,
    XOR = 645,
    WAVE_XOR = 646,
    XOR_WAVE = 647,
    EQ2_QMARK = 648,
    NEQ_QMARK = 649,
    RSHIFT2 = 650,
    LSHIFT2 = 651,
    LT_DASH_RT = 652,
    APOSTROPHE_GND = 653,
    APOSTROPHE_VDD = 654,
    LP_STAR = 655,
    STAR_RP = 656,
    DOLLAR_UNIT_ = 657,
    TOKEN_400 = 658,
    SV_UNSIGNED_NUMBER = 659,
    SV_DECIMAL_NUMBER = 660,
    SV_OCTAL_NUMBER = 661,
    SV_BINARY_NUMBER = 662,
    SV_HEX_NUMBER = 663,
    SV_UNSIGNED_INTEGER = 664,
    SV_EXPONENTIAL_NUMBER = 665,
    SV_FIXED_POINT_NUMBER = 666,
    SV_STRING = 667,
    SV_ESCAPED_IDENTIFIER = 668,
    SV_IDENTIFIER = 669,
    FILE_PATH = 670,
    SV_INTEGER = 671
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "parser.yy" /* yacc.c:1909  */

    char token_str[MAX_TOKEN_LEN];
    class ast::list<class ast::object *> *ast_list;
    
    ast::library_text                             *ast_library_text;
    ast::library_description                      *ast_library_description;
    ast::library_declaration                      *ast_library_declaration;
    ast::include_statement                        *ast_include_statement;
    ast::source_text                              *ast_source_text;
    ast::description                              *ast_description;
    ast::module_nonansi_header                    *ast_module_nonansi_header;
    ast::module_ansi_header                       *ast_module_ansi_header;
    ast::module_declaration                       *ast_module_declaration;
    ast::module_keyword                           *ast_module_keyword;
    ast::interface_declaration                    *ast_interface_declaration;
    ast::interface_nonansi_header                 *ast_interface_nonansi_header;
    ast::interface_ansi_header                    *ast_interface_ansi_header;
    ast::program_declaration                      *ast_program_declaration;
    ast::program_nonansi_header                   *ast_program_nonansi_header;
    ast::program_ansi_header                      *ast_program_ansi_header;
    ast::checker_declaration                      *ast_checker_declaration;
    ast::class_declaration                        *ast_class_declaration;
    ast::interface_class_type                     *ast_interface_class_type;
    ast::package_declaration                      *ast_package_declaration;
    ast::timeunits_declaration                    *ast_timeunits_declaration;
    ast::parameter_port_list                      *ast_parameter_port_list;
    ast::parameter_port_declaration               *ast_parameter_port_declaration;
    ast::list_of_ports                            *ast_list_of_ports;
    ast::list_of_port_declarations                *ast_list_of_port_declarations;
    ast::port_declaration                         *ast_port_declaration;
    ast::port                                     *ast_port;
    ast::port_expression                          *ast_port_expression;
    ast::port_reference                           *ast_port_reference;
    ast::port_direction                           *ast_port_direction;
    ast::net_port_header                          *ast_net_port_header;
    ast::variable_port_header                     *ast_variable_port_header;
    ast::interface_port_header                    *ast_interface_port_header;
    ast::ansi_port_declaration                    *ast_ansi_port_declaration;
    ast::elaboration_system_task                  *ast_elaboration_system_task;
    ast::finish_number                            *ast_finish_number;
    ast::module_common_item                       *ast_module_common_item;
    ast::module_item                              *ast_module_item;
    ast::module_or_generate_item                  *ast_module_or_generate_item;
    ast::module_or_generate_item_declaration      *ast_module_or_generate_item_declaration;
    ast::non_port_module_item                     *ast_non_port_module_item;
    ast::parameter_override                       *ast_parameter_override;
    ast::bind_directive                           *ast_bind_directive;
    ast::bind_target_scope                        *ast_bind_target_scope;
    ast::bind_target_instance                     *ast_bind_target_instance;
    ast::bind_target_instance_list                *ast_bind_target_instance_list;
    ast::bind_instantiation                       *ast_bind_instantiation;
    ast::config_declaration                       *ast_config_declaration;
    ast::design_statement                         *ast_design_statement;
    ast::config_rule_statement                    *ast_config_rule_statement;
    ast::default_clause                           *ast_default_clause;
    ast::inst_clause                              *ast_inst_clause;
    ast::inst_name                                *ast_inst_name;
    ast::cell_clause                              *ast_cell_clause;
    ast::liblist_clause                           *ast_liblist_clause;
    ast::use_clause                               *ast_use_clause;
    ast::interface_or_generate_item               *ast_interface_or_generate_item;
    ast::extern_tf_declaration                    *ast_extern_tf_declaration;
    ast::interface_item                           *ast_interface_item;
    ast::non_port_interface_item                  *ast_non_port_interface_item;
    ast::program_item                             *ast_program_item;
    ast::non_port_program_item                    *ast_non_port_program_item;
    ast::program_generate_item                    *ast_program_generate_item;
    ast::checker_port_list                        *ast_checker_port_list;
    ast::checker_port_item                        *ast_checker_port_item;
    ast::checker_port_direction                   *ast_checker_port_direction;
    ast::checker_or_generate_item                 *ast_checker_or_generate_item;
    ast::checker_or_generate_item_declaration     *ast_checker_or_generate_item_declaration;
    ast::checker_generate_item                    *ast_checker_generate_item;
    ast::class_item                               *ast_class_item;
    ast::class_property                           *ast_class_property;
    ast::class_method                             *ast_class_method;
    ast::class_constructor_prototype              *ast_class_constructor_prototype;
    ast::class_constraint                         *ast_class_constraint;
    ast::class_item_qualifier                     *ast_class_item_qualifier;
    ast::property_qualifier                       *ast_property_qualifier;
    ast::random_qualifier                         *ast_random_qualifier;
    ast::method_qualifier                         *ast_method_qualifier;
    ast::method_prototype                         *ast_method_prototype;
    ast::class_constructor_declaration            *ast_class_constructor_declaration;
    ast::constraint_declaration                   *ast_constraint_declaration;
    ast::constraint_block                         *ast_constraint_block;
    ast::constraint_block_item                    *ast_constraint_block_item;
    ast::solve_before_list                        *ast_solve_before_list;
    ast::constraint_primary                       *ast_constraint_primary;
    ast::constraint_expression                    *ast_constraint_expression;
    ast::uniqueness_constraint                    *ast_uniqueness_constraint;
    ast::constraint_set                           *ast_constraint_set;
    ast::dist_list                                *ast_dist_list;
    ast::dist_item                                *ast_dist_item;
    ast::dist_weight                              *ast_dist_weight;
    ast::constraint_prototype                     *ast_constraint_prototype;
    ast::constraint_prototype_qualifier           *ast_constraint_prototype_qualifier;
    ast::extern_constraint_declaration            *ast_extern_constraint_declaration;
    ast::identifier_list                          *ast_identifier_list;
    ast::package_item                             *ast_package_item;
    ast::package_or_generate_item_declaration     *ast_package_or_generate_item_declaration;
    ast::anonymous_program                        *ast_anonymous_program;
    ast::anonymous_program_item                   *ast_anonymous_program_item;
    ast::local_parameter_declaration              *ast_local_parameter_declaration;
    ast::parameter_declaration                    *ast_parameter_declaration;
    ast::specparam_declaration                    *ast_specparam_declaration;
    ast::inout_declaration                        *ast_inout_declaration;
    ast::input_declaration                        *ast_input_declaration;
    ast::output_declaration                       *ast_output_declaration;
    ast::interface_port_declaration               *ast_interface_port_declaration;
    ast::ref_declaration                          *ast_ref_declaration;
    ast::data_declaration                         *ast_data_declaration;
    ast::package_import_declaration               *ast_package_import_declaration;
    ast::package_import_item                      *ast_package_import_item;
    ast::package_export_declaration               *ast_package_export_declaration;
    ast::genvar_declaration                       *ast_genvar_declaration;
    ast::net_declaration                          *ast_net_declaration;
    ast::type_declaration                         *ast_type_declaration;
    ast::net_type_declaration                     *ast_net_type_declaration;
    ast::lifetime                                 *ast_lifetime;
    ast::casting_type                             *ast_casting_type;
    ast::data_type                                *ast_data_type;
    ast::data_type_or_implicit                    *ast_data_type_or_implicit;
    ast::implicit_data_type                       *ast_implicit_data_type;
    ast::enum_base_type                           *ast_enum_base_type;
    ast::enum_name_declaration                    *ast_enum_name_declaration;
    ast::class_scope                              *ast_class_scope;
    ast::class_type                               *ast_class_type;
    ast::integer_type                             *ast_integer_type;
    ast::integer_atom_type                        *ast_integer_atom_type;
    ast::integer_vector_type                      *ast_integer_vector_type;
    ast::non_integer_type                         *ast_non_integer_type;
    ast::net_type                                 *ast_net_type;
    ast::net_port_type                            *ast_net_port_type;
    ast::variable_port_type                       *ast_variable_port_type;
    ast::var_data_type                            *ast_var_data_type;
    ast::signing                                  *ast_signing;
    ast::simple_type                              *ast_simple_type;
    ast::struct_union_member                      *ast_struct_union_member;
    ast::data_type_or_void                        *ast_data_type_or_void;
    ast::struct_union                             *ast_struct_union;
    ast::type_reference                           *ast_type_reference;
    ast::drive_strength                           *ast_drive_strength;
    ast::strength0                                *ast_strength0;
    ast::strength1                                *ast_strength1;
    ast::charge_strength                          *ast_charge_strength;
    ast::delay3                                   *ast_delay3;
    ast::delay2                                   *ast_delay2;
    ast::delay_value                              *ast_delay_value;
    ast::list_of_defparam_assignments             *ast_list_of_defparam_assignments;
    ast::list_of_genvar_identifiers               *ast_list_of_genvar_identifiers;
    ast::list_of_interface_identifiers            *ast_list_of_interface_identifiers;
    ast::list_of_net_decl_assignments             *ast_list_of_net_decl_assignments;
    ast::list_of_param_assignments                *ast_list_of_param_assignments;
    ast::list_of_port_identifiers                 *ast_list_of_port_identifiers;
    ast::list_of_udp_port_identifiers             *ast_list_of_udp_port_identifiers;
    ast::list_of_specparam_assignments            *ast_list_of_specparam_assignments;
    ast::list_of_tf_variable_identifiers          *ast_list_of_tf_variable_identifiers;
    ast::list_of_type_assignments                 *ast_list_of_type_assignments;
    ast::list_of_variable_decl_assignments        *ast_list_of_variable_decl_assignments;
    ast::list_of_variable_identifiers             *ast_list_of_variable_identifiers;
    ast::list_of_variable_port_identifiers        *ast_list_of_variable_port_identifiers;
    ast::defparam_assignment                      *ast_defparam_assignment;
    ast::net_decl_assignment                      *ast_net_decl_assignment;
    ast::param_assignment                         *ast_param_assignment;
    ast::specparam_assignment                     *ast_specparam_assignment;
    ast::type_assignment                          *ast_type_assignment;
    ast::pulse_control_specparam                  *ast_pulse_control_specparam;
    ast::error_limit_value                        *ast_error_limit_value;
    ast::reject_limit_value                       *ast_reject_limit_value;
    ast::limit_value                              *ast_limit_value;
    ast::variable_decl_assignment                 *ast_variable_decl_assignment;
    ast::class_new                                *ast_class_new;
    ast::dynamic_array_new                        *ast_dynamic_array_new;
    ast::unpacked_dimension                       *ast_unpacked_dimension;
    ast::packed_dimension                         *ast_packed_dimension;
    ast::associative_dimension                    *ast_associative_dimension;
    ast::variable_dimension                       *ast_variable_dimension;
    ast::queue_dimension                          *ast_queue_dimension;
    ast::unsized_dimension                        *ast_unsized_dimension;
    ast::function_data_type_or_implicit           *ast_function_data_type_or_implicit;
    ast::function_declaration                     *ast_function_declaration;
    ast::function_body_declaration                *ast_function_body_declaration;
    ast::function_prototype                       *ast_function_prototype;
    ast::dpi_import_export                        *ast_dpi_import_export;
    ast::dpi_spec_string                          *ast_dpi_spec_string;
    ast::dpi_function_import_property             *ast_dpi_function_import_property;
    ast::dpi_task_import_property                 *ast_dpi_task_import_property;
    ast::dpi_function_proto                       *ast_dpi_function_proto;
    ast::dpi_task_proto                           *ast_dpi_task_proto;
    ast::task_declaration                         *ast_task_declaration;
    ast::task_body_declaration                    *ast_task_body_declaration;
    ast::tf_item_declaration                      *ast_tf_item_declaration;
    ast::tf_port_list                             *ast_tf_port_list;
    ast::tf_port_item                             *ast_tf_port_item;
    ast::tf_port_direction                        *ast_tf_port_direction;
    ast::tf_port_declaration                      *ast_tf_port_declaration;
    ast::task_prototype                           *ast_task_prototype;
    ast::block_item_declaration                   *ast_block_item_declaration;
    ast::overload_declaration                     *ast_overload_declaration;
    ast::overload_operator                        *ast_overload_operator;
    ast::overload_proto_formals                   *ast_overload_proto_formals;
    ast::modport_declaration                      *ast_modport_declaration;
    ast::modport_item                             *ast_modport_item;
    ast::modport_ports_declaration                *ast_modport_ports_declaration;
    ast::modport_clocking_declaration             *ast_modport_clocking_declaration;
    ast::modport_simple_ports_declaration         *ast_modport_simple_ports_declaration;
    ast::modport_simple_port                      *ast_modport_simple_port;
    ast::modport_tf_ports_declaration             *ast_modport_tf_ports_declaration;
    ast::modport_tf_port                          *ast_modport_tf_port;
    ast::import_export                            *ast_import_export;
    ast::concurrent_assertion_item                *ast_concurrent_assertion_item;
    ast::concurrent_assertion_statement           *ast_concurrent_assertion_statement;
    ast::assert_property_statement                *ast_assert_property_statement;
    ast::assume_property_statement                *ast_assume_property_statement;
    ast::cover_property_statement                 *ast_cover_property_statement;
    ast::expect_property_statement                *ast_expect_property_statement;
    ast::cover_sequence_statement                 *ast_cover_sequence_statement;
    ast::restrict_property_statement              *ast_restrict_property_statement;
    ast::property_instance                        *ast_property_instance;
    ast::property_list_of_arguments               *ast_property_list_of_arguments;
    ast::property_actual_arg                      *ast_property_actual_arg;
    ast::assertion_item_declaration               *ast_assertion_item_declaration;
    ast::property_declaration                     *ast_property_declaration;
    ast::property_port_list                       *ast_property_port_list;
    ast::property_port_item                       *ast_property_port_item;
    ast::property_lvar_port_direction             *ast_property_lvar_port_direction;
    ast::property_formal_type                     *ast_property_formal_type;
    ast::property_spec                            *ast_property_spec;
    ast::property_expr                            *ast_property_expr;
    ast::property_case_item                       *ast_property_case_item;
    ast::sequence_declaration                     *ast_sequence_declaration;
    ast::sequence_port_list                       *ast_sequence_port_list;
    ast::sequence_port_item                       *ast_sequence_port_item;
    ast::sequence_lvar_port_direction             *ast_sequence_lvar_port_direction;
    ast::sequence_formal_type                     *ast_sequence_formal_type;
    ast::sequence_expr                            *ast_sequence_expr;
    ast::cycle_delay_range                        *ast_cycle_delay_range;
    ast::sequence_method_call                     *ast_sequence_method_call;
    ast::sequence_match_item                      *ast_sequence_match_item;
    ast::sequence_instance                        *ast_sequence_instance;
    ast::sequence_list_of_arguments               *ast_sequence_list_of_arguments;
    ast::sequence_actual_arg                      *ast_sequence_actual_arg;
    ast::boolean_abbrev                           *ast_boolean_abbrev;
    ast::sequence_abbrev                          *ast_sequence_abbrev;
    ast::consecutive_repetition                   *ast_consecutive_repetition;
    ast::non_consecutive_repetition               *ast_non_consecutive_repetition;
    ast::goto_repetition                          *ast_goto_repetition;
    ast::const_or_range_expression                *ast_const_or_range_expression;
    ast::cycle_delay_const_range_expression       *ast_cycle_delay_const_range_expression;
    ast::expression_or_dist                       *ast_expression_or_dist;
    ast::assertion_variable_declaration           *ast_assertion_variable_declaration;
    ast::let_declaration                          *ast_let_declaration;
    ast::let_identifier                           *ast_let_identifier;
    ast::let_port_list                            *ast_let_port_list;
    ast::let_port_item                            *ast_let_port_item;
    ast::let_formal_type                          *ast_let_formal_type;
    ast::let_expression                           *ast_let_expression;
    ast::let_list_of_arguments                    *ast_let_list_of_arguments;
    ast::let_actual_arg                           *ast_let_actual_arg;
    ast::covergroup_declaration                   *ast_covergroup_declaration;
    ast::coverage_spec_or_option                  *ast_coverage_spec_or_option;
    ast::coverage_option                          *ast_coverage_option;
    ast::coverage_spec                            *ast_coverage_spec;
    ast::coverage_event                           *ast_coverage_event;
    ast::block_event_expression                   *ast_block_event_expression;
    ast::hierarchical_btf_identifier              *ast_hierarchical_btf_identifier;
    ast::cover_point                              *ast_cover_point;
    ast::bins_or_empty                            *ast_bins_or_empty;
    ast::bins_or_options                          *ast_bins_or_options;
    ast::bins_keyword                             *ast_bins_keyword;
    ast::trans_list                               *ast_trans_list;
    ast::trans_set                                *ast_trans_set;
    ast::trans_range_list                         *ast_trans_range_list;
    ast::trans_item                               *ast_trans_item;
    ast::repeat_range                             *ast_repeat_range;
    ast::cover_cross                              *ast_cover_cross;
    ast::list_of_cross_items                      *ast_list_of_cross_items;
    ast::cross_item                               *ast_cross_item;
    ast::cross_body                               *ast_cross_body;
    ast::cross_body_item                          *ast_cross_body_item;
    ast::bins_selection_or_option                 *ast_bins_selection_or_option;
    ast::bins_selection                           *ast_bins_selection;
    ast::select_expression                        *ast_select_expression;
    ast::select_condition                         *ast_select_condition;
    ast::bins_expression                          *ast_bins_expression;
    ast::covergroup_range_list                    *ast_covergroup_range_list;
    ast::covergroup_value_range                   *ast_covergroup_value_range;
    ast::with_covergroup_expression               *ast_with_covergroup_expression;
    ast::set_covergroup_expression                *ast_set_covergroup_expression;
    ast::integer_covergroup_expression            *ast_integer_covergroup_expression;
    ast::cross_set_expression                     *ast_cross_set_expression;
    ast::covergroup_expression                    *ast_covergroup_expression;
    ast::gate_instantiation                       *ast_gate_instantiation;
    ast::cmos_switch_instance                     *ast_cmos_switch_instance;
    ast::enable_gate_instance                     *ast_enable_gate_instance;
    ast::mos_switch_instance                      *ast_mos_switch_instance;
    ast::n_input_gate_instance                    *ast_n_input_gate_instance;
    ast::n_output_gate_instance                   *ast_n_output_gate_instance;
    ast::pass_switch_instance                     *ast_pass_switch_instance;
    ast::pass_enable_switch_instance              *ast_pass_enable_switch_instance;
    ast::pull_gate_instance                       *ast_pull_gate_instance;
    ast::pulldown_strength                        *ast_pulldown_strength;
    ast::pullup_strength                          *ast_pullup_strength;
    ast::enable_terminal                          *ast_enable_terminal;
    ast::inout_terminal                           *ast_inout_terminal;
    ast::input_terminal                           *ast_input_terminal;
    ast::ncontrol_terminal                        *ast_ncontrol_terminal;
    ast::output_terminal                          *ast_output_terminal;
    ast::pcontrol_terminal                        *ast_pcontrol_terminal;
    ast::cmos_switchtype                          *ast_cmos_switchtype;
    ast::enable_gatetype                          *ast_enable_gatetype;
    ast::mos_switchtype                           *ast_mos_switchtype;
    ast::n_input_gatetype                         *ast_n_input_gatetype;
    ast::n_output_gatetype                        *ast_n_output_gatetype;
    ast::pass_en_switchtype                       *ast_pass_en_switchtype;
    ast::pass_switchtype                          *ast_pass_switchtype;
    ast::module_instantiation                     *ast_module_instantiation;
    ast::parameter_value_assignment               *ast_parameter_value_assignment;
    ast::list_of_parameter_assignments            *ast_list_of_parameter_assignments;
    ast::ordered_parameter_assignment             *ast_ordered_parameter_assignment;
    ast::named_parameter_assignment               *ast_named_parameter_assignment;
    ast::hierarchical_instance                    *ast_hierarchical_instance;
    ast::name_of_instance                         *ast_name_of_instance;
    ast::list_of_port_connections                 *ast_list_of_port_connections;
    ast::ordered_port_connection                  *ast_ordered_port_connection;
    ast::named_port_connection                    *ast_named_port_connection;
    ast::interface_instantiation                  *ast_interface_instantiation;
    ast::program_instantiation                    *ast_program_instantiation;
    ast::checker_instantiation                    *ast_checker_instantiation;
    ast::list_of_checker_port_connections         *ast_list_of_checker_port_connections;
    ast::ordered_checker_port_connection          *ast_ordered_checker_port_connection;
    ast::named_checker_port_connection            *ast_named_checker_port_connection;
    ast::generate_region                          *ast_generate_region;
    ast::loop_generate_construct                  *ast_loop_generate_construct;
    ast::genvar_initialization                    *ast_genvar_initialization;
    ast::genvar_iteration                         *ast_genvar_iteration;
    ast::conditional_generate_construct           *ast_conditional_generate_construct;
    ast::if_generate_construct                    *ast_if_generate_construct;
    ast::case_generate_construct                  *ast_case_generate_construct;
    ast::case_generate_item                       *ast_case_generate_item;
    ast::generate_block                           *ast_generate_block;
    ast::generate_item                            *ast_generate_item;
    ast::udp_nonansi_declaration                  *ast_udp_nonansi_declaration;
    ast::udp_ansi_declaration                     *ast_udp_ansi_declaration;
    ast::udp_declaration                          *ast_udp_declaration;
    ast::udp_port_list                            *ast_udp_port_list;
    ast::udp_declaration_port_list                *ast_udp_declaration_port_list;
    ast::udp_port_declaration                     *ast_udp_port_declaration;
    ast::udp_output_declaration                   *ast_udp_output_declaration;
    ast::udp_input_declaration                    *ast_udp_input_declaration;
    ast::udp_reg_declaration                      *ast_udp_reg_declaration;
    ast::udp_body                                 *ast_udp_body;
    ast::combinational_body                       *ast_combinational_body;
    ast::combinational_entry                      *ast_combinational_entry;
    ast::sequential_body                          *ast_sequential_body;
    ast::udp_initial_statement                    *ast_udp_initial_statement;
    ast::init_val                                 *ast_init_val;
    ast::sequential_entry                         *ast_sequential_entry;
    ast::seq_input_list                           *ast_seq_input_list;
    ast::level_input_list                         *ast_level_input_list;
    ast::edge_input_list                          *ast_edge_input_list;
    ast::edge_indicator                           *ast_edge_indicator;
    ast::current_state                            *ast_current_state;
    ast::next_state                               *ast_next_state;
    ast::output_symbol                            *ast_output_symbol;
    ast::level_symbol                             *ast_level_symbol;
    ast::edge_symbol                              *ast_edge_symbol;
    ast::udp_instantiation                        *ast_udp_instantiation;
    ast::udp_instance                             *ast_udp_instance;
    ast::continuous_assign                        *ast_continuous_assign;
    ast::list_of_net_assignments                  *ast_list_of_net_assignments;
    ast::list_of_variable_assignments             *ast_list_of_variable_assignments;
    ast::net_alias                                *ast_net_alias;
    ast::net_assignment                           *ast_net_assignment;
    ast::initial_construct                        *ast_initial_construct;
    ast::always_construct                         *ast_always_construct;
    ast::always_keyword                           *ast_always_keyword;
    ast::final_construct                          *ast_final_construct;
    ast::blocking_assignment                      *ast_blocking_assignment;
    ast::operator_assignment                      *ast_operator_assignment;
    ast::assignment_operator                      *ast_assignment_operator;
    ast::nonblocking_assignment                   *ast_nonblocking_assignment;
    ast::procedural_continuous_assignment         *ast_procedural_continuous_assignment;
    ast::variable_assignment                      *ast_variable_assignment;
    ast::action_block                             *ast_action_block;
    ast::seq_block                                *ast_seq_block;
    ast::par_block                                *ast_par_block;
    ast::join_keyword                             *ast_join_keyword;
    ast::statement_or_null                        *ast_statement_or_null;
    ast::statement                                *ast_statement;
    ast::statement_item                           *ast_statement_item;
    ast::function_statement                       *ast_function_statement;
    ast::function_statement_or_null               *ast_function_statement_or_null;
    ast::variable_identifier_list                 *ast_variable_identifier_list;
    ast::procedural_timing_control_statement      *ast_procedural_timing_control_statement;
    ast::delay_or_event_control                   *ast_delay_or_event_control;
    ast::delay_control                            *ast_delay_control;
    ast::event_control                            *ast_event_control;
    ast::event_expression                         *ast_event_expression;
    ast::procedural_timing_control                *ast_procedural_timing_control;
    ast::jump_statement                           *ast_jump_statement;
    ast::wait_statement                           *ast_wait_statement;
    ast::event_trigger                            *ast_event_trigger;
    ast::disable_statement                        *ast_disable_statement;
    ast::conditional_statement                    *ast_conditional_statement;
    ast::unique_priority                          *ast_unique_priority;
    ast::cond_predicate                           *ast_cond_predicate;
    ast::expression_or_cond_pattern               *ast_expression_or_cond_pattern;
    ast::cond_pattern                             *ast_cond_pattern;
    ast::case_statement                           *ast_case_statement;
    ast::case_keyword                             *ast_case_keyword;
    ast::case_expression                          *ast_case_expression;
    ast::case_item                                *ast_case_item;
    ast::case_pattern_item                        *ast_case_pattern_item;
    ast::case_inside_item                         *ast_case_inside_item;
    ast::case_item_expression                     *ast_case_item_expression;
    ast::randcase_statement                       *ast_randcase_statement;
    ast::randcase_item                            *ast_randcase_item;
    ast::open_range_list                          *ast_open_range_list;
    ast::open_value_range                         *ast_open_value_range;
    ast::pattern                                  *ast_pattern;
    ast::assignment_pattern                       *ast_assignment_pattern;
    ast::structure_pattern_key                    *ast_structure_pattern_key;
    ast::array_pattern_key                        *ast_array_pattern_key;
    ast::assignment_pattern_key                   *ast_assignment_pattern_key;
    ast::assignment_pattern_expression            *ast_assignment_pattern_expression;
    ast::assignment_pattern_expression_type       *ast_assignment_pattern_expression_type;
    ast::constant_assignment_pattern_expression   *ast_constant_assignment_pattern_expression;
    ast::assignment_pattern_net_lvalue            *ast_assignment_pattern_net_lvalue;
    ast::assignment_pattern_variable_lvalue       *ast_assignment_pattern_variable_lvalue;
    ast::loop_statement                           *ast_loop_statement;
    ast::for_initialization                       *ast_for_initialization;
    ast::for_variable_declaration                 *ast_for_variable_declaration;
    ast::for_step                                 *ast_for_step;
    ast::for_step_assignment                      *ast_for_step_assignment;
    ast::loop_variables                           *ast_loop_variables;
    ast::subroutine_call_statement                *ast_subroutine_call_statement;
    ast::assertion_item                           *ast_assertion_item;
    ast::deferred_immediate_assertion_item        *ast_deferred_immediate_assertion_item;
    ast::procedural_assertion_statement           *ast_procedural_assertion_statement;
    ast::immediate_assertion_statement            *ast_immediate_assertion_statement;
    ast::simple_immediate_assertion_statement     *ast_simple_immediate_assertion_statement;
    ast::simple_immediate_assert_statement        *ast_simple_immediate_assert_statement;
    ast::simple_immediate_assume_statement        *ast_simple_immediate_assume_statement;
    ast::simple_immediate_cover_statement         *ast_simple_immediate_cover_statement;
    ast::deferred_immediate_assertion_statement   *ast_deferred_immediate_assertion_statement;
    ast::deferred_immediate_assert_statement      *ast_deferred_immediate_assert_statement;
    ast::deferred_immediate_assume_statement      *ast_deferred_immediate_assume_statement;
    ast::deferred_immediate_cover_statement       *ast_deferred_immediate_cover_statement;
    ast::clocking_declaration                     *ast_clocking_declaration;
    ast::clocking_event                           *ast_clocking_event;
    ast::clocking_item                            *ast_clocking_item;
    ast::default_skew                             *ast_default_skew;
    ast::clocking_direction                       *ast_clocking_direction;
    ast::list_of_clocking_decl_assign             *ast_list_of_clocking_decl_assign;
    ast::clocking_decl_assign                     *ast_clocking_decl_assign;
    ast::clocking_skew                            *ast_clocking_skew;
    ast::clocking_drive                           *ast_clocking_drive;
    ast::cycle_delay                              *ast_cycle_delay;
    ast::clockvar                                 *ast_clockvar;
    ast::clockvar_expression                      *ast_clockvar_expression;
    ast::randsequence_statement                   *ast_randsequence_statement;
    ast::production                               *ast_production;
    ast::rs_rule                                  *ast_rs_rule;
    ast::rs_production_list                       *ast_rs_production_list;
    ast::weight_specification                     *ast_weight_specification;
    ast::rs_code_block                            *ast_rs_code_block;
    ast::rs_prod                                  *ast_rs_prod;
    ast::production_item                          *ast_production_item;
    ast::rs_if_else                               *ast_rs_if_else;
    ast::rs_repeat                                *ast_rs_repeat;
    ast::rs_case                                  *ast_rs_case;
    ast::rs_case_item                             *ast_rs_case_item;
    ast::specify_block                            *ast_specify_block;
    ast::specify_item                             *ast_specify_item;
    ast::pulsestyle_declaration                   *ast_pulsestyle_declaration;
    ast::showcancelled_declaration                *ast_showcancelled_declaration;
    ast::path_declaration                         *ast_path_declaration;
    ast::simple_path_declaration                  *ast_simple_path_declaration;
    ast::parallel_path_description                *ast_parallel_path_description;
    ast::full_path_description                    *ast_full_path_description;
    ast::list_of_path_inputs                      *ast_list_of_path_inputs;
    ast::list_of_path_outputs                     *ast_list_of_path_outputs;
    ast::specify_input_terminal_descriptor        *ast_specify_input_terminal_descriptor;
    ast::specify_output_terminal_descriptor       *ast_specify_output_terminal_descriptor;
    ast::input_identifier                         *ast_input_identifier;
    ast::output_identifier                        *ast_output_identifier;
    ast::path_delay_value                         *ast_path_delay_value;
    ast::list_of_path_delay_expressions           *ast_list_of_path_delay_expressions;
    ast::t_path_delay_expression                  *ast_t_path_delay_expression;
    ast::trise_path_delay_expression              *ast_trise_path_delay_expression;
    ast::tfall_path_delay_expression              *ast_tfall_path_delay_expression;
    ast::tz_path_delay_expression                 *ast_tz_path_delay_expression;
    ast::t01_path_delay_expression                *ast_t01_path_delay_expression;
    ast::t10_path_delay_expression                *ast_t10_path_delay_expression;
    ast::t0z_path_delay_expression                *ast_t0z_path_delay_expression;
    ast::tz1_path_delay_expression                *ast_tz1_path_delay_expression;
    ast::t1z_path_delay_expression                *ast_t1z_path_delay_expression;
    ast::tz0_path_delay_expression                *ast_tz0_path_delay_expression;
    ast::t0x_path_delay_expression                *ast_t0x_path_delay_expression;
    ast::tx1_path_delay_expression                *ast_tx1_path_delay_expression;
    ast::t1x_path_delay_expression                *ast_t1x_path_delay_expression;
    ast::tx0_path_delay_expression                *ast_tx0_path_delay_expression;
    ast::txz_path_delay_expression                *ast_txz_path_delay_expression;
    ast::tzx_path_delay_expression                *ast_tzx_path_delay_expression;
    ast::path_delay_expression                    *ast_path_delay_expression;
    ast::edge_sensitive_path_declaration          *ast_edge_sensitive_path_declaration;
    ast::parallel_edge_sensitive_path_description *ast_parallel_edge_sensitive_path_description;
    ast::full_edge_sensitive_path_description     *ast_full_edge_sensitive_path_description;
    ast::data_source_expression                   *ast_data_source_expression;
    ast::edge_identifier                          *ast_edge_identifier;
    ast::state_dependent_path_declaration         *ast_state_dependent_path_declaration;
    ast::polarity_operator                        *ast_polarity_operator;
    ast::system_timing_check                      *ast_system_timing_check;
    ast::dollarsign_setup_timing_check            *ast_dollarsign_setup_timing_check;
    ast::dollarsign_hold_timing_check             *ast_dollarsign_hold_timing_check;
    ast::dollarsign_setuphold_timing_check        *ast_dollarsign_setuphold_timing_check;
    ast::dollarsign_recovery_timing_check         *ast_dollarsign_recovery_timing_check;
    ast::dollarsign_removal_timing_check          *ast_dollarsign_removal_timing_check;
    ast::dollarsign_recrem_timing_check           *ast_dollarsign_recrem_timing_check;
    ast::dollarsign_skew_timing_check             *ast_dollarsign_skew_timing_check;
    ast::dollarsign_timeskew_timing_check         *ast_dollarsign_timeskew_timing_check;
    ast::dollarsign_fullskew_timing_check         *ast_dollarsign_fullskew_timing_check;
    ast::dollarsign_period_timing_check           *ast_dollarsign_period_timing_check;
    ast::dollarsign_width_timing_check            *ast_dollarsign_width_timing_check;
    ast::dollarsign_nochange_timing_check         *ast_dollarsign_nochange_timing_check;
    ast::timecheck_condition                      *ast_timecheck_condition;
    ast::controlled_reference_event               *ast_controlled_reference_event;
    ast::data_event                               *ast_data_event;
    ast::delayed_data                             *ast_delayed_data;
    ast::delayed_reference                        *ast_delayed_reference;
    ast::end_edge_offset                          *ast_end_edge_offset;
    ast::event_based_flag                         *ast_event_based_flag;
    ast::notifier                                 *ast_notifier;
    ast::reference_event                          *ast_reference_event;
    ast::remain_active_flag                       *ast_remain_active_flag;
    ast::timestamp_condition                      *ast_timestamp_condition;
    ast::start_edge_offset                        *ast_start_edge_offset;
    ast::threshold                                *ast_threshold;
    ast::timing_check_limit                       *ast_timing_check_limit;
    ast::timing_check_event                       *ast_timing_check_event;
    ast::controlled_timing_check_event            *ast_controlled_timing_check_event;
    ast::timing_check_event_control               *ast_timing_check_event_control;
    ast::specify_terminal_descriptor              *ast_specify_terminal_descriptor;
    ast::edge_control_specifier                   *ast_edge_control_specifier;
    ast::edge_descriptor                          *ast_edge_descriptor;
    ast::zero_or_one                              *ast_zero_or_one;
    ast::z_or_x                                   *ast_z_or_x;
    ast::timing_check_condition                   *ast_timing_check_condition;
    ast::scalar_timing_check_condition            *ast_scalar_timing_check_condition;
    ast::scalar_constant                          *ast_scalar_constant;
    ast::concatenation                            *ast_concatenation;
    ast::constant_concatenation                   *ast_constant_concatenation;
    ast::constant_multiple_concatenation          *ast_constant_multiple_concatenation;
    ast::module_path_concatenation                *ast_module_path_concatenation;
    ast::module_path_multiple_concatenation       *ast_module_path_multiple_concatenation;
    ast::multiple_concatenation                   *ast_multiple_concatenation;
    ast::streaming_concatenation                  *ast_streaming_concatenation;
    ast::stream_operator                          *ast_stream_operator;
    ast::slice_size                               *ast_slice_size;
    ast::stream_concatenation                     *ast_stream_concatenation;
    ast::stream_expression                        *ast_stream_expression;
    ast::array_range_expression                   *ast_array_range_expression;
    ast::empty_queue                              *ast_empty_queue;
    ast::constant_function_call                   *ast_constant_function_call;
    ast::tf_call                                  *ast_tf_call;
    ast::system_tf_call                           *ast_system_tf_call;
    ast::subroutine_call                          *ast_subroutine_call;
    ast::function_subroutine_call                 *ast_function_subroutine_call;
    ast::list_of_arguments                        *ast_list_of_arguments;
    ast::method_call                              *ast_method_call;
    ast::method_call_body                         *ast_method_call_body;
    ast::built_in_method_call                     *ast_built_in_method_call;
    ast::array_manipulation_call                  *ast_array_manipulation_call;
    ast::randomize_call                           *ast_randomize_call;
    ast::method_call_root                         *ast_method_call_root;
    ast::array_method_name                        *ast_array_method_name;
    ast::inc_or_dec_expression                    *ast_inc_or_dec_expression;
    ast::conditional_expression                   *ast_conditional_expression;
    ast::constant_expression                      *ast_constant_expression;
    ast::constant_mintypmax_expression            *ast_constant_mintypmax_expression;
    ast::constant_param_expression                *ast_constant_param_expression;
    ast::param_expression                         *ast_param_expression;
    ast::constant_range_expression                *ast_constant_range_expression;
    ast::constant_part_select_range               *ast_constant_part_select_range;
    ast::constant_range                           *ast_constant_range;
    ast::constant_indexed_range                   *ast_constant_indexed_range;
    ast::expression                               *ast_expression;
    ast::tagged_union_expression                  *ast_tagged_union_expression;
    ast::inside_expression                        *ast_inside_expression;
    ast::value_range                              *ast_value_range;
    ast::mintypmax_expression                     *ast_mintypmax_expression;
    ast::module_path_conditional_expression       *ast_module_path_conditional_expression;
    ast::module_path_expression                   *ast_module_path_expression;
    ast::module_path_mintypmax_expression         *ast_module_path_mintypmax_expression;
    ast::part_select_range                        *ast_part_select_range;
    ast::indexed_range                            *ast_indexed_range;
    ast::genvar_expression                        *ast_genvar_expression;
    ast::constant_primary                         *ast_constant_primary;
    ast::module_path_primary                      *ast_module_path_primary;
    ast::primary                                  *ast_primary;
    ast::class_qualifier                          *ast_class_qualifier;
    ast::range_expression                         *ast_range_expression;
    ast::primary_literal                          *ast_primary_literal;
    ast::time_literal                             *ast_time_literal;
    ast::time_unit                                *ast_time_unit;
    ast::implicit_class_handle                    *ast_implicit_class_handle;
    ast::bit_select                               *ast_bit_select;
    ast::select                                   *ast_select;
    ast::nonrange_select                          *ast_nonrange_select;
    ast::constant_bit_select                      *ast_constant_bit_select;
    ast::constant_select                          *ast_constant_select;
    ast::constant_cast                            *ast_constant_cast;
    ast::constant_let_expression                  *ast_constant_let_expression;
    ast::cast                                     *ast_cast;
    ast::net_lvalue                               *ast_net_lvalue;
    ast::variable_lvalue                          *ast_variable_lvalue;
    ast::nonrange_variable_lvalue                 *ast_nonrange_variable_lvalue;
    ast::unary_operator                           *ast_unary_operator;
    ast::binary_operator                          *ast_binary_operator;
    ast::inc_or_dec_operator                      *ast_inc_or_dec_operator;
    ast::unary_module_path_operator               *ast_unary_module_path_operator;
    ast::binary_module_path_operator              *ast_binary_module_path_operator;
    ast::number                                   *ast_number;
    ast::integral_number                          *ast_integral_number;
    ast::decimal_number                           *ast_decimal_number;
    ast::octal_number                             *ast_octal_number;
    ast::binary_number                            *ast_binary_number;
    ast::hex_number                               *ast_hex_number;
    ast::unsigned_number                          *ast_unsigned_number;
    ast::real_number                              *ast_real_number;
    ast::fixed_point_number                       *ast_fixed_point_number;
    ast::unbased_unsized_literal                  *ast_unbased_unsized_literal;
    ast::string_literal                           *ast_string_literal;
    ast::attribute_instance                       *ast_attribute_instance;
    ast::attr_spec                                *ast_attr_spec;
    ast::attr_name                                *ast_attr_name;
    ast::block_identifier                         *ast_block_identifier;
    ast::bin_identifier                           *ast_bin_identifier;
    ast::c_identifier                             *ast_c_identifier;
    ast::cell_identifier                          *ast_cell_identifier;
    ast::checker_identifier                       *ast_checker_identifier;
    ast::class_identifier                         *ast_class_identifier;
    ast::class_variable_identifier                *ast_class_variable_identifier;
    ast::clocking_identifier                      *ast_clocking_identifier;
    ast::config_identifier                        *ast_config_identifier;
    ast::const_identifier                         *ast_const_identifier;
    ast::constraint_identifier                    *ast_constraint_identifier;
    ast::covergroup_identifier                    *ast_covergroup_identifier;
    ast::cover_point_identifier                   *ast_cover_point_identifier;
    ast::cross_identifier                         *ast_cross_identifier;
    ast::dynamic_array_variable_identifier        *ast_dynamic_array_variable_identifier;
    ast::enum_identifier                          *ast_enum_identifier;
    ast::escaped_identifier                       *ast_escaped_identifier;
    ast::formal_port_identifier                   *ast_formal_port_identifier;
    ast::function_identifier                      *ast_function_identifier;
    ast::generate_block_identifier                *ast_generate_block_identifier;
    ast::genvar_identifier                        *ast_genvar_identifier;
    ast::hierarchical_array_identifier            *ast_hierarchical_array_identifier;
    ast::hierarchical_block_identifier            *ast_hierarchical_block_identifier;
    ast::hierarchical_event_identifier            *ast_hierarchical_event_identifier;
    ast::hierarchical_identifier                  *ast_hierarchical_identifier;
    ast::hierarchical_net_identifier              *ast_hierarchical_net_identifier;
    ast::hierarchical_parameter_identifier        *ast_hierarchical_parameter_identifier;
    ast::hierarchical_property_identifier         *ast_hierarchical_property_identifier;
    ast::hierarchical_sequence_identifier         *ast_hierarchical_sequence_identifier;
    ast::hierarchical_task_identifier             *ast_hierarchical_task_identifier;
    ast::hierarchical_tf_identifier               *ast_hierarchical_tf_identifier;
    ast::hierarchical_variable_identifier         *ast_hierarchical_variable_identifier;
    ast::identifier                               *ast_identifier;
    ast::index_variable_identifier                *ast_index_variable_identifier;
    ast::interface_identifier                     *ast_interface_identifier;
    ast::interface_instance_identifier            *ast_interface_instance_identifier;
    ast::inout_port_identifier                    *ast_inout_port_identifier;
    ast::input_port_identifier                    *ast_input_port_identifier;
    ast::instance_identifier                      *ast_instance_identifier;
    ast::library_identifier                       *ast_library_identifier;
    ast::member_identifier                        *ast_member_identifier;
    ast::method_identifier                        *ast_method_identifier;
    ast::modport_identifier                       *ast_modport_identifier;
    ast::module_identifier                        *ast_module_identifier;
    ast::net_identifier                           *ast_net_identifier;
    ast::net_type_identifier                      *ast_net_type_identifier;
    ast::output_port_identifier                   *ast_output_port_identifier;
    ast::package_identifier                       *ast_package_identifier;
    ast::package_scope                            *ast_package_scope;
    ast::parameter_identifier                     *ast_parameter_identifier;
    ast::port_identifier                          *ast_port_identifier;
    ast::production_identifier                    *ast_production_identifier;
    ast::program_identifier                       *ast_program_identifier;
    ast::property_identifier                      *ast_property_identifier;
    ast::ps_class_identifier                      *ast_ps_class_identifier;
    ast::ps_covergroup_identifier                 *ast_ps_covergroup_identifier;
    ast::ps_checker_identifier                    *ast_ps_checker_identifier;
    ast::ps_identifier                            *ast_ps_identifier;
    ast::ps_or_hierarchical_array_identifier      *ast_ps_or_hierarchical_array_identifier;
    ast::ps_or_hierarchical_net_identifier        *ast_ps_or_hierarchical_net_identifier;
    ast::ps_or_hierarchical_property_identifier   *ast_ps_or_hierarchical_property_identifier;
    ast::ps_or_hierarchical_sequence_identifier   *ast_ps_or_hierarchical_sequence_identifier;
    ast::ps_or_hierarchical_tf_identifier         *ast_ps_or_hierarchical_tf_identifier;
    ast::ps_parameter_identifier                  *ast_ps_parameter_identifier;
    ast::ps_type_identifier                       *ast_ps_type_identifier;
    ast::sequence_identifier                      *ast_sequence_identifier;
    ast::signal_identifier                        *ast_signal_identifier;
    ast::simple_identifier                        *ast_simple_identifier;
    ast::specparam_identifier                     *ast_specparam_identifier;
    ast::system_tf_identifier                     *ast_system_tf_identifier;
    ast::task_identifier                          *ast_task_identifier;
    ast::tf_identifier                            *ast_tf_identifier;
    ast::terminal_identifier                      *ast_terminal_identifier;
    ast::topmodule_identifier                     *ast_topmodule_identifier;
    ast::type_identifier                          *ast_type_identifier;
    ast::udp_identifier                           *ast_udp_identifier;
    ast::variable_identifier                      *ast_variable_identifier;
    ast::file_path_spec                           *ast_file_path_spec;

#line 1189 "/home/handy/Dropbox/linux/work/yacc/metacc/latest/build/out/parser.tab.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HANDY_DROPBOX_LINUX_WORK_YACC_METACC_LATEST_BUILD_OUT_PARSER_TAB_HH_INCLUDED  */
