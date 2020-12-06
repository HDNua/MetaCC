%{
#include <cstdio>
#include <cstdlib>

#include "parser_ast.h"
const int MAX_TOKEN_LEN = 2048;



class ast::object *start;
class ast::object *start_library_text;
class ast::object *start_source_text;



int yylex();
int yyerror(char const *str);

%}
%union {
    char token_str[MAX_TOKEN_LEN];
    class ast::list<class ast::object *> *ast_list;
    
    ast::line_list *ast_line_list;
    ast::line      *ast_line;
    ast::expr      *ast_expr;
    ast::term      *ast_term;
    ast::primary   *ast_primary;
    ast::attribute *ast_attribute;
}



%token SEMICOLON /* ; */
%token LIBRARY_ /* library */
%token COMMA /* , */
%token DASH_INCDIR_ /* -incdir */
%token INCLUDE_ /* include */
%token ENDMODULE_ /* endmodule */
%token COLON /* : */
%token EXTERN_ /* extern */
%token MODULE_ /* module */
%token MACROMODULE_ /* macromodule */
%token ENDINTERFACE_ /* endinterface */
%token INTERFACE_ /* interface */
%token LP /* ( */
%token DOT_STAR /* .* */
%token RP /* ) */
%token ENDPROGRAM_ /* endprogram */
%token PROGRAM_ /* program */
%token CHECKER_ /* checker */
%token ENDCHECKER_ /* endchecker */
%token VIRTUAL_ /* virtual */
%token CLASS_ /* class */
%token EXTENDS_ /* extends */
%token IMPLEMENTS_ /* implements */
%token ENDCLASS_ /* endclass */
%token PACKAGE_ /* package */
%token ENDPACKAGE_ /* endpackage */
%token TIMEUNIT_ /* timeunit */
%token SLASH /* / */
%token TIMEPRECISION_ /* timeprecision */
%token SHARP /* # */
%token TYPE_ /* type */
%token DOT /* . */
%token LMP /* { */
%token RMP /* } */
%token INPUT_ /* input */
%token OUTPUT_ /* output */
%token INOUT_ /* inout */
%token REF_ /* ref */
%token EQ /* = */
%token DOLLAR_FATAL_ /* dollarsign_fatal */
%token DOLLAR_ERROR_ /* dollarsign_error */
%token DOLLAR_WARNING_ /* dollarsign_warning */
%token DOLLAR_INFO_ /* dollarsign_info */
%token ZERO_ /* 0 */
%token ONE_ /* 1 */
%token TWO_ /* 2 */
%token DEFAULT_ /* default */
%token CLOCKING_ /* clocking */
%token DISABLE_ /* disable */
%token IFF_ /* iff */
%token DEFPARAM_ /* defparam */
%token BIND_ /* bind */
%token CONFIG_ /* config */
%token ENDCONFIG_ /* endconfig */
%token DESIGN_ /* design */
%token INSTANCE_ /* instance */
%token CELL_ /* cell */
%token LIBLIST_ /* liblist */
%token USE_ /* use */
%token FORKJOIN_ /* forkjoin */
%token RAND_ /* rand */
%token CONST_ /* const */
%token PURE_ /* pure */
%token FUNCTION_ /* function */
%token NEW_ /* new */
%token STATIC_ /* static */
%token PROTECTED_ /* protected */
%token LOCAL_ /* local */
%token RANDC_ /* randc */
%token SUPER_ /* super */
%token ENDFUNCTION_ /* endfunction */
%token CONSTRAINT_ /* constraint */
%token SOLVE_ /* solve */
%token BEFORE_ /* before */
%token SOFT_ /* soft */
%token RIGHTARROW /* -> */
%token IF_ /* if */
%token ELSE_ /* else */
%token FOREACH_ /* foreach */
%token LSP /* [ */
%token RSP /* ] */
%token UNIQUE_ /* unique */
%token COLON_EQUAL /* := */
%token COLON_SLASH /* :/ */
%token LOCALPARAM_ /* localparam */
%token PARAMETER_ /* parameter */
%token SPECPARAM_ /* specparam */
%token VAR_ /* var */
%token IMPORT_ /* import */
%token COLON2 /* :: */
%token STAR /* * */
%token EXPORT_ /* export */
%token STAR_COLON2_STAR /* *::* */
%token GENVAR_ /* genvar */
%token VECTORED_ /* vectored */
%token SCALARED_ /* scalared */
%token INTERCONNECT_ /* interconnect */
%token TYPEDEF_ /* typedef */
%token ENUM_ /* enum */
%token STRUCT_ /* struct */
%token UNION_ /* union */
%token NETTYPE_ /* nettype */
%token WITH_ /* with */
%token AUTOMATIC_ /* automatic */
%token STRING_ /* string */
%token PACKED_ /* packed */
%token CHANDLE_ /* chandle */
%token EVENT_ /* event */
%token BYTE_ /* byte */
%token SHORTINT_ /* shortint */
%token INT_ /* int */
%token LONGINT_ /* longint */
%token INTEGER_ /* integer */
%token TIME_ /* time */
%token BIT_ /* bit */
%token LOGIC_ /* logic */
%token REG_ /* reg */
%token SHORTREAL_ /* shortreal */
%token REAL_ /* real */
%token REALTIME_ /* realtime */
%token SUPPLY0_ /* supply0 */
%token SUPPLY1_ /* supply1 */
%token TRI_ /* tri */
%token TRIAND_ /* triand */
%token TRIOR_ /* trior */
%token TRIREG_ /* trireg */
%token TRI0_ /* tri0 */
%token TRI1_ /* tri1 */
%token UWIRE_ /* uwire */
%token WIRE_ /* wire */
%token WAND_ /* wand */
%token WOR_ /* wor */
%token SIGNED_ /* signed */
%token UNSIGNED_ /* unsigned */
%token VOID_ /* void */
%token TAGGED_ /* tagged */
%token HIGHZ1_ /* highz1 */
%token HIGHZ0_ /* highz0 */
%token STRONG0_ /* strong0 */
%token PULL0_ /* pull0 */
%token WEAK0_ /* weak0 */
%token STRONG1_ /* strong1 */
%token PULL1_ /* pull1 */
%token WEAK1_ /* weak1 */
%token SMALL_ /* small */
%token MEDIUM_ /* medium */
%token LARGE_ /* large */
%token ONESTEP_ /* 1step */
%token DOLLAR_ /* dollarsign_ */
%token TASK_ /* task */
%token DPI_C_ /* DPI-C */
%token DPI_ /* DPI */
%token CONTEXT_ /* context */
%token ENDTASK_ /* endtask */
%token PLUS /* + */
%token PLUS2 /* ++ */
%token MINUS /* - */
%token MINUS2 /* -- */
%token STAR2 /* ** */
%token PERCENT /* % */
%token EQ2 /* == */
%token NEQ /* != */
%token LT /* < */
%token LTE /* <= */
%token GT /* > */
%token GTE /* >= */
%token MODPORT_ /* modport */
%token ASSERT_ /* assert */
%token PROPERTY_ /* property */
%token ASSUME_ /* assume */
%token COVER_ /* cover */
%token EXPECT_ /* expect */
%token SEQUENCE_ /* sequence */
%token RESTRICT_ /* restrict */
%token ENDPROPERTY_ /* endproperty */
%token STRONG_ /* strong */
%token WEAK_ /* weak */
%token NOT_ /* not */
%token OR_ /* or */
%token AND_ /* and */
%token BAR_DASH_GT /* |-> */
%token BAR_EQ_GT /* |=> */
%token CASE_ /* case */
%token ENDCASE_ /* endcase */
%token SHARP_DASH_SHARP /* #-# */
%token SHARP_EQ_SHARP /* #=# */
%token NEXTTIME_ /* nexttime */
%token S_NEXTTIME_ /* s_nexttime */
%token ALWAYS_ /* always */
%token S_ALWAYS_ /* s_always */
%token S_EVENTUALLY_ /* s_eventually */
%token UNTIL_ /* until */
%token S_UNTIL_ /* s_until */
%token UNTIL_WITH_ /* until_with */
%token S_UNTIL_WITH_ /* s_until_with */
%token IMPLIES_ /* implies */
%token ACCEPT_ON_ /* accept_on */
%token REJECT_ON_ /* reject_on */
%token SYNC_ACCEPT_ON_ /* sync_accept_on */
%token SYNC_REJECT_ON_ /* sync_reject_on */
%token ENDSEQUENCE_ /* endsequence */
%token UNTYPED_ /* untyped */
%token INTERSECT_ /* intersect */
%token FIRST_MATCH_ /* first_match */
%token THROUGHOUT_ /* throughout */
%token WITHIN_ /* within */
%token SHARP2 /* ## */
%token LSP_STAR_RSP /* [*] */
%token LSP_PLUS_RSP /* [+] */
%token LSP_STAR /* [* */
%token LSP_EQ /* [= */
%token LSP_DASH_GT /* [-> */
%token DIST_ /* dist */
%token LET_ /* let */
%token COVERGROUP_ /* covergroup */
%token ENDGROUP_ /* endgroup */
%token OPTION_ /* option */
%token TYPE_OPTION_ /* type_option */
%token SAMPLE_ /* sample */
%token AT2 /* @@ */
%token BEGIN_ /* begin */
%token END_ /* end */
%token COVERPOINT_ /* coverpoint */
%token WILDCARD_ /* wildcard */
%token BINS_ /* bins */
%token ILLEGRAL_BINS_ /* illegal_bins */
%token IGNORE_BINS_ /* ignore_bins */
%token EQ_GT /* => */
%token CROSS_ /* cross */
%token NOT /* ! */
%token AND2 /* && */
%token BAR2 /* || */
%token MATCHES_ /* matches */
%token BINSOF_ /* binsof */
%token PULLDOWN_ /* pulldown */
%token PULLUP_ /* pullup */
%token CMOS_ /* cmos */
%token RCMOS_ /* rcmos */
%token BUFIF0_ /* bufif0 */
%token BUFIF1_ /* bufif1 */
%token NOTIF0_ /* notif0 */
%token NOTIF1_ /* notif1 */
%token NMOS_ /* nmos */
%token PMOS_ /* pmos */
%token RNMOS_ /* rnmos */
%token RPMOS_ /* rpmos */
%token NAND_ /* nand */
%token NOR_ /* nor */
%token XOR_ /* xor */
%token XNOR_ /* xnor */
%token BUF_ /* buf */
%token TRANIF0_ /* tranif0 */
%token TRANIF1_ /* tranif1 */
%token RTRANIF0_ /* rtranif0 */
%token RTRANIF1_ /* rtranif1 */
%token TRAN_ /* tran */
%token RTRAN_ /* rtran */
%token GENERATE_ /* generate */
%token ENDGENERATE_ /* endgenerate */
%token FOR_ /* for */
%token PRIMITIVE_ /* primitive */
%token ENDPRIMITIVE_ /* endprimitive */
%token TABLE_ /* table */
%token ENDTABLE_ /* endtable */
%token INITIAL_ /* initial */
%token ONEBIT_GND /* 1'b0 */
%token ONEBIT_VDD /* 1'b1 */
%token ONEBIT_X0 /* 1'bx */
%token ONEBIT_X1 /* 1'bX */
%token ONEBIT_BGND /* 1'B0 */
%token ONEBIT_BVDD /* 1'B1 */
%token ONEBIT_BX0 /* 1'Bx */
%token ONEBIT_BX1 /* 1'BX */
%token LETTER_X0_ /* x */
%token LETTER_X1_ /* X */
%token QMARK /* ? */
%token LETTER_B0_ /* b */
%token LETTER_B1_ /* B */
%token LETTER_R0_ /* r */
%token LETTER_R1_ /* R */
%token LETTER_F0_ /* f */
%token LETTER_F1_ /* F */
%token LETTER_P0_ /* p */
%token LETTER_P1_ /* P */
%token LETTER_N0_ /* n */
%token LETTER_N1_ /* N */
%token ASSIGN_ /* assign */
%token ALIAS_ /* alias */
%token ALWAYS_COMB_ /* always_comb */
%token ALWAYS_LATCH_ /* always_latch */
%token ALWAYS_FF_ /* always_ff */
%token FINAL_ /* final */
%token PLUS_EQ /* += */
%token MINUS_EQ /* -= */
%token STAR_EQ /* *= */
%token SLASH_EQ /* /= */
%token PERCENT_EQ /* %= */
%token AND_EQ /* &= */
%token BAR_EQ /* |= */
%token XOR_EQ /* ^= */
%token LSHIFT_EQ /* <<= */
%token RSHIFT_EQ /* >>= */
%token LSHIFT2_EQ /* <<<= */
%token RSHIFT2_EQ /* >>>= */
%token DEASSIGN_ /* deassign */
%token FORCE_ /* force */
%token RELEASE_ /* release */
%token FORK_ /* fork */
%token JOIN_ /* join */
%token JOIN_ANY_ /* join_any */
%token JOIN_NONE_ /* join_none */
%token REPEAT_ /* repeat */
%token AT /* @ */
%token RETURN_ /* return */
%token BREAK_ /* break */
%token CONTINUE_ /* continue */
%token WAIT_ /* wait */
%token WAIT_ORDER_ /* wait_order */
%token DASH_RSHIFT /* ->> */
%token UNIQUE0_ /* unique0 */
%token PRIORITY_ /* priority */
%token AND3 /* &&& */
%token INSIDE_ /* inside */
%token CASEX_ /* casex */
%token CASEZ_ /* casez */
%token RANDCASE_ /* randcase */
%token APOSTROPHE /* ' */
%token FOREVER_ /* forever */
%token WHILE_ /* while */
%token DO_ /* do */
%token SHARP0_ /* #0 */
%token ENDCLOCKING_ /* endclocking */
%token GLOBAL_ /* global */
%token RANDSEQUENCE_ /* randsequence */
%token BAR_ /* | */
%token SPECIFY_ /* specify */
%token ENDSPECIFY_ /* endspecify */
%token PULSESTYLE_ONEVENT_ /* pulsestyle_onevent */
%token PULSESTYPE_ONDETECT_ /* pulsestyle_ondetect */
%token SHOWCANCELLED_ /* showcancelled */
%token NOSHOWCANCELLED_ /* noshowcancelled */
%token STAR_RT /* *> */
%token POSEDGE_ /* posedge */
%token NEGEDGE_ /* negedge */
%token EDGE_ /* edge */
%token IFNONE_ /* ifnone */
%token DOLLAR_SETUP_ /* dollarsign_setup */
%token DOLLAR_HOLD_ /* dollarsign_hold */
%token DOLLAR_SETUPHOLD_ /* dollarsign_setuphold */
%token DOLLAR_RECOVERY_ /* dollarsign_recovery */
%token DOLLAR_REMOVAL_ /* dollarsign_removal */
%token DOLLAR_RECREM_ /* dollarsign_recrem */
%token DOLLAR_SKEW_ /* dollarsign_skew */
%token DOLLAR_TIMESKEW_ /* dollarsign_timeskew */
%token DOLLAR_FULLSKEW_ /* dollarsign_fullskew */
%token DOLLAR_PERIOD_ /* dollarsign_period */
%token DOLLAR_WIDTH_ /* dollarsign_width */
%token DOLLAR_NOCHANGE_ /* dollarsign_nochange */
%token ZERO_ONE /* 01 */
%token ONE_ZERO /* 10 */
%token LETTER_Z0_ /* z */
%token LETTER_Z1_ /* Z */
%token WAVE /* ~ */
%token EQ3 /* === */
%token NEQ2 /* !== */
%token APOSTROPHE_B0_GND /* 'b0 */
%token APOSTROPHE_B0_VDD /* 'b1 */
%token APOSTROPHE_B1_GND /* 'B0 */
%token APOSTROPHE_B1_VDD /* 'B1 */
%token RSHIFT /* >> */
%token LSHIFT /* << */
%token PLUS_COLON /* +: */
%token MINUS_COLON /* -: */
%token STD_COLON2 /* std:: */
%token RANDOMIZE_ /* randomize */
%token NULL_ /* null */
%token THIS_ /* this */
%token LOCAL_COLON2 /* local:: */
%token LETTER_S0_ /* s */
%token MS_ /* ms */
%token US_ /* us */
%token NS_ /* ns */
%token PS_ /* ps */
%token FS_ /* fs */
%token AND /* & */
%token WAVE_AND /* ~& */
%token WAVE_BAR /* ~| */
%token XOR /* ^ */
%token WAVE_XOR /* ~^ */
%token XOR_WAVE /* ^~ */
%token EQ2_QMARK /* ==? */
%token NEQ_QMARK /* !=? */
%token RSHIFT2 /* >>> */
%token LSHIFT2 /* <<< */
%token LT_DASH_RT /* <-> */
%token APOSTROPHE_GND /* '0 */
%token APOSTROPHE_VDD /* '1 */
%token LP_STAR /* (* */
%token STAR_RP /* *) */
%token DOLLAR_UNIT_ /* dollarsign_unit */
%token SV_UNSIGNED_INTEGER /* SV_UNSIGNED_INTEGER */
%token SV_STRING    /* SV_STRING */
%token SV_IDENTIFIER /* SV_IDENTIFIER */
%token SV_INTEGER

%type <ast_line_list>   line_list
%type <ast_line>        line
%type <ast_expr>        expr
%type <ast_term>        term
%type <ast_primary>     primary
%type <ast_attribute>   attribute
%type <ast_list> LIST_0
%type <token_str> SEMICOLON
%type <token_str> LIBRARY_
%type <token_str> COMMA
%type <token_str> DASH_INCDIR_
%type <token_str> INCLUDE_
%type <token_str> ENDMODULE_
%type <token_str> COLON
%type <token_str> EXTERN_
%type <token_str> MODULE_
%type <token_str> MACROMODULE_
%type <token_str> ENDINTERFACE_
%type <token_str> INTERFACE_
%type <token_str> LP
%type <token_str> DOT_STAR
%type <token_str> RP
%type <token_str> ENDPROGRAM_
%type <token_str> PROGRAM_
%type <token_str> CHECKER_
%type <token_str> ENDCHECKER_
%type <token_str> VIRTUAL_
%type <token_str> CLASS_
%type <token_str> EXTENDS_
%type <token_str> IMPLEMENTS_
%type <token_str> ENDCLASS_
%type <token_str> PACKAGE_
%type <token_str> ENDPACKAGE_
%type <token_str> TIMEUNIT_
%type <token_str> SLASH
%type <token_str> TIMEPRECISION_
%type <token_str> SHARP
%type <token_str> TYPE_
%type <token_str> DOT
%type <token_str> LMP
%type <token_str> RMP
%type <token_str> INPUT_
%type <token_str> OUTPUT_
%type <token_str> INOUT_
%type <token_str> REF_
%type <token_str> EQ
%type <token_str> DOLLAR_FATAL_
%type <token_str> DOLLAR_ERROR_
%type <token_str> DOLLAR_WARNING_
%type <token_str> DOLLAR_INFO_
%type <token_str> ZERO_
%type <token_str> ONE_
%type <token_str> TWO_
%type <token_str> DEFAULT_
%type <token_str> CLOCKING_
%type <token_str> DISABLE_
%type <token_str> IFF_
%type <token_str> DEFPARAM_
%type <token_str> BIND_
%type <token_str> CONFIG_
%type <token_str> ENDCONFIG_
%type <token_str> DESIGN_
%type <token_str> INSTANCE_
%type <token_str> CELL_
%type <token_str> LIBLIST_
%type <token_str> USE_
%type <token_str> FORKJOIN_
%type <token_str> RAND_
%type <token_str> CONST_
%type <token_str> PURE_
%type <token_str> FUNCTION_
%type <token_str> NEW_
%type <token_str> STATIC_
%type <token_str> PROTECTED_
%type <token_str> LOCAL_
%type <token_str> RANDC_
%type <token_str> SUPER_
%type <token_str> ENDFUNCTION_
%type <token_str> CONSTRAINT_
%type <token_str> SOLVE_
%type <token_str> BEFORE_
%type <token_str> SOFT_
%type <token_str> RIGHTARROW
%type <token_str> IF_
%type <token_str> ELSE_
%type <token_str> FOREACH_
%type <token_str> LSP
%type <token_str> RSP
%type <token_str> UNIQUE_
%type <token_str> COLON_EQUAL
%type <token_str> COLON_SLASH
%type <token_str> LOCALPARAM_
%type <token_str> PARAMETER_
%type <token_str> SPECPARAM_
%type <token_str> VAR_
%type <token_str> IMPORT_
%type <token_str> COLON2
%type <token_str> STAR
%type <token_str> EXPORT_
%type <token_str> STAR_COLON2_STAR
%type <token_str> GENVAR_
%type <token_str> VECTORED_
%type <token_str> SCALARED_
%type <token_str> INTERCONNECT_
%type <token_str> TYPEDEF_
%type <token_str> ENUM_
%type <token_str> STRUCT_
%type <token_str> UNION_
%type <token_str> NETTYPE_
%type <token_str> WITH_
%type <token_str> AUTOMATIC_
%type <token_str> STRING_
%type <token_str> PACKED_
%type <token_str> CHANDLE_
%type <token_str> EVENT_
%type <token_str> BYTE_
%type <token_str> SHORTINT_
%type <token_str> INT_
%type <token_str> LONGINT_
%type <token_str> INTEGER_
%type <token_str> TIME_
%type <token_str> BIT_
%type <token_str> LOGIC_
%type <token_str> REG_
%type <token_str> SHORTREAL_
%type <token_str> REAL_
%type <token_str> REALTIME_
%type <token_str> SUPPLY0_
%type <token_str> SUPPLY1_
%type <token_str> TRI_
%type <token_str> TRIAND_
%type <token_str> TRIOR_
%type <token_str> TRIREG_
%type <token_str> TRI0_
%type <token_str> TRI1_
%type <token_str> UWIRE_
%type <token_str> WIRE_
%type <token_str> WAND_
%type <token_str> WOR_
%type <token_str> SIGNED_
%type <token_str> UNSIGNED_
%type <token_str> VOID_
%type <token_str> TAGGED_
%type <token_str> HIGHZ1_
%type <token_str> HIGHZ0_
%type <token_str> STRONG0_
%type <token_str> PULL0_
%type <token_str> WEAK0_
%type <token_str> STRONG1_
%type <token_str> PULL1_
%type <token_str> WEAK1_
%type <token_str> SMALL_
%type <token_str> MEDIUM_
%type <token_str> LARGE_
%type <token_str> ONESTEP_
%type <token_str> DOLLAR_
%type <token_str> TASK_
%type <token_str> DPI_C_
%type <token_str> DPI_
%type <token_str> CONTEXT_
%type <token_str> ENDTASK_
%type <token_str> PLUS
%type <token_str> PLUS2
%type <token_str> MINUS
%type <token_str> MINUS2
%type <token_str> STAR2
%type <token_str> PERCENT
%type <token_str> EQ2
%type <token_str> NEQ
%type <token_str> LT
%type <token_str> LTE
%type <token_str> GT
%type <token_str> GTE
%type <token_str> MODPORT_
%type <token_str> ASSERT_
%type <token_str> PROPERTY_
%type <token_str> ASSUME_
%type <token_str> COVER_
%type <token_str> EXPECT_
%type <token_str> SEQUENCE_
%type <token_str> RESTRICT_
%type <token_str> ENDPROPERTY_
%type <token_str> STRONG_
%type <token_str> WEAK_
%type <token_str> NOT_
%type <token_str> OR_
%type <token_str> AND_
%type <token_str> BAR_DASH_GT
%type <token_str> BAR_EQ_GT
%type <token_str> CASE_
%type <token_str> ENDCASE_
%type <token_str> SHARP_DASH_SHARP
%type <token_str> SHARP_EQ_SHARP
%type <token_str> NEXTTIME_
%type <token_str> S_NEXTTIME_
%type <token_str> ALWAYS_
%type <token_str> S_ALWAYS_
%type <token_str> S_EVENTUALLY_
%type <token_str> UNTIL_
%type <token_str> S_UNTIL_
%type <token_str> UNTIL_WITH_
%type <token_str> S_UNTIL_WITH_
%type <token_str> IMPLIES_
%type <token_str> ACCEPT_ON_
%type <token_str> REJECT_ON_
%type <token_str> SYNC_ACCEPT_ON_
%type <token_str> SYNC_REJECT_ON_
%type <token_str> ENDSEQUENCE_
%type <token_str> UNTYPED_
%type <token_str> INTERSECT_
%type <token_str> FIRST_MATCH_
%type <token_str> THROUGHOUT_
%type <token_str> WITHIN_
%type <token_str> SHARP2
%type <token_str> LSP_STAR_RSP
%type <token_str> LSP_PLUS_RSP
%type <token_str> LSP_STAR
%type <token_str> LSP_EQ
%type <token_str> LSP_DASH_GT
%type <token_str> DIST_
%type <token_str> LET_
%type <token_str> COVERGROUP_
%type <token_str> ENDGROUP_
%type <token_str> OPTION_
%type <token_str> TYPE_OPTION_
%type <token_str> SAMPLE_
%type <token_str> AT2
%type <token_str> BEGIN_
%type <token_str> END_
%type <token_str> COVERPOINT_
%type <token_str> WILDCARD_
%type <token_str> BINS_
%type <token_str> ILLEGRAL_BINS_
%type <token_str> IGNORE_BINS_
%type <token_str> EQ_GT
%type <token_str> CROSS_
%type <token_str> NOT
%type <token_str> AND2
%type <token_str> BAR2
%type <token_str> MATCHES_
%type <token_str> BINSOF_
%type <token_str> PULLDOWN_
%type <token_str> PULLUP_
%type <token_str> CMOS_
%type <token_str> RCMOS_
%type <token_str> BUFIF0_
%type <token_str> BUFIF1_
%type <token_str> NOTIF0_
%type <token_str> NOTIF1_
%type <token_str> NMOS_
%type <token_str> PMOS_
%type <token_str> RNMOS_
%type <token_str> RPMOS_
%type <token_str> NAND_
%type <token_str> NOR_
%type <token_str> XOR_
%type <token_str> XNOR_
%type <token_str> BUF_
%type <token_str> TRANIF0_
%type <token_str> TRANIF1_
%type <token_str> RTRANIF0_
%type <token_str> RTRANIF1_
%type <token_str> TRAN_
%type <token_str> RTRAN_
%type <token_str> GENERATE_
%type <token_str> ENDGENERATE_
%type <token_str> FOR_
%type <token_str> PRIMITIVE_
%type <token_str> ENDPRIMITIVE_
%type <token_str> TABLE_
%type <token_str> ENDTABLE_
%type <token_str> INITIAL_
%type <token_str> ONEBIT_GND
%type <token_str> ONEBIT_VDD
%type <token_str> ONEBIT_X0
%type <token_str> ONEBIT_X1
%type <token_str> ONEBIT_BGND
%type <token_str> ONEBIT_BVDD
%type <token_str> ONEBIT_BX0
%type <token_str> ONEBIT_BX1
%type <token_str> LETTER_X0_
%type <token_str> LETTER_X1_
%type <token_str> QMARK
%type <token_str> LETTER_B0_
%type <token_str> LETTER_B1_
%type <token_str> LETTER_R0_
%type <token_str> LETTER_R1_
%type <token_str> LETTER_F0_
%type <token_str> LETTER_F1_
%type <token_str> LETTER_P0_
%type <token_str> LETTER_P1_
%type <token_str> LETTER_N0_
%type <token_str> LETTER_N1_
%type <token_str> ASSIGN_
%type <token_str> ALIAS_
%type <token_str> ALWAYS_COMB_
%type <token_str> ALWAYS_LATCH_
%type <token_str> ALWAYS_FF_
%type <token_str> FINAL_
%type <token_str> PLUS_EQ
%type <token_str> MINUS_EQ
%type <token_str> STAR_EQ
%type <token_str> SLASH_EQ
%type <token_str> PERCENT_EQ
%type <token_str> AND_EQ
%type <token_str> BAR_EQ
%type <token_str> XOR_EQ
%type <token_str> LSHIFT_EQ
%type <token_str> RSHIFT_EQ
%type <token_str> LSHIFT2_EQ
%type <token_str> RSHIFT2_EQ
%type <token_str> DEASSIGN_
%type <token_str> FORCE_
%type <token_str> RELEASE_
%type <token_str> FORK_
%type <token_str> JOIN_
%type <token_str> JOIN_ANY_
%type <token_str> JOIN_NONE_
%type <token_str> REPEAT_
%type <token_str> AT
%type <token_str> RETURN_
%type <token_str> BREAK_
%type <token_str> CONTINUE_
%type <token_str> WAIT_
%type <token_str> WAIT_ORDER_
%type <token_str> DASH_RSHIFT
%type <token_str> UNIQUE0_
%type <token_str> PRIORITY_
%type <token_str> AND3
%type <token_str> INSIDE_
%type <token_str> CASEX_
%type <token_str> CASEZ_
%type <token_str> RANDCASE_
%type <token_str> APOSTROPHE
%type <token_str> FOREVER_
%type <token_str> WHILE_
%type <token_str> DO_
%type <token_str> SHARP0_
%type <token_str> ENDCLOCKING_
%type <token_str> GLOBAL_
%type <token_str> RANDSEQUENCE_
%type <token_str> BAR_
%type <token_str> SPECIFY_
%type <token_str> ENDSPECIFY_
%type <token_str> PULSESTYLE_ONEVENT_
%type <token_str> PULSESTYPE_ONDETECT_
%type <token_str> SHOWCANCELLED_
%type <token_str> NOSHOWCANCELLED_
%type <token_str> STAR_RT
%type <token_str> POSEDGE_
%type <token_str> NEGEDGE_
%type <token_str> EDGE_
%type <token_str> IFNONE_
%type <token_str> DOLLAR_SETUP_
%type <token_str> DOLLAR_HOLD_
%type <token_str> DOLLAR_SETUPHOLD_
%type <token_str> DOLLAR_RECOVERY_
%type <token_str> DOLLAR_REMOVAL_
%type <token_str> DOLLAR_RECREM_
%type <token_str> DOLLAR_SKEW_
%type <token_str> DOLLAR_TIMESKEW_
%type <token_str> DOLLAR_FULLSKEW_
%type <token_str> DOLLAR_PERIOD_
%type <token_str> DOLLAR_WIDTH_
%type <token_str> DOLLAR_NOCHANGE_
%type <token_str> ZERO_ONE
%type <token_str> ONE_ZERO
%type <token_str> LETTER_Z0_
%type <token_str> LETTER_Z1_
%type <token_str> WAVE
%type <token_str> EQ3
%type <token_str> NEQ2
%type <token_str> APOSTROPHE_B0_GND
%type <token_str> APOSTROPHE_B0_VDD
%type <token_str> APOSTROPHE_B1_GND
%type <token_str> APOSTROPHE_B1_VDD
%type <token_str> RSHIFT
%type <token_str> LSHIFT
%type <token_str> PLUS_COLON
%type <token_str> MINUS_COLON
%type <token_str> STD_COLON2
%type <token_str> RANDOMIZE_
%type <token_str> NULL_
%type <token_str> THIS_
%type <token_str> LOCAL_COLON2
%type <token_str> LETTER_S0_
%type <token_str> MS_
%type <token_str> US_
%type <token_str> NS_
%type <token_str> PS_
%type <token_str> FS_
%type <token_str> AND
%type <token_str> WAVE_AND
%type <token_str> WAVE_BAR
%type <token_str> XOR
%type <token_str> WAVE_XOR
%type <token_str> XOR_WAVE
%type <token_str> EQ2_QMARK
%type <token_str> NEQ_QMARK
%type <token_str> RSHIFT2
%type <token_str> LSHIFT2
%type <token_str> LT_DASH_RT
%type <token_str> APOSTROPHE_GND
%type <token_str> APOSTROPHE_VDD
%type <token_str> LP_STAR
%type <token_str> STAR_RP
%type <token_str> DOLLAR_UNIT_
%type <token_str> SV_UNSIGNED_INTEGER
%type <token_str> SV_STRING
%type <token_str> SV_IDENTIFIER
%type <token_str> SV_INTEGER


%%




start
	: library_text
	{
		start_library_text = $1;
	}
	| source_text
	{
		start_source_text = $1;
	}
	;





line_list 
    : LIST_0 
    {
        ast::line_list *ret = new ast::line_list;
        $$ = ret;
    }
    ;

line 
    : expr SEMICOLON /* ; */ 
    {
        ast::line *ret = new ast::line;
        $$ = ret;
    }
    ;

expr 
    : expr PLUS /* + */ term 
    {
        ast::expr *ret = new ast::expr;
        $$ = ret;
    }
    | expr MINUS /* - */ term 
    {
        ast::expr *ret = new ast::expr;
        $$ = ret;
    }
    | term 
    {
        ast::expr *ret = new ast::expr;
        $$ = ret;
    }
    ;

term 
    : term STAR /* * */ primary 
    {
        ast::term *ret = new ast::term;
        $$ = ret;
    }
    | term SLASH /* / */ primary 
    {
        ast::term *ret = new ast::term;
        $$ = ret;
    }
    | primary 
    {
        ast::term *ret = new ast::term;
        $$ = ret;
    }
    ;

primary 
    : SV_UNSIGNED_INTEGER 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | SV_STRING 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | SV_IDENTIFIER 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | LP /* ( */ expr RP /* ) */ 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    ;

attribute 
    : SV_IDENTIFIER 
    {
        ast::attribute *ret = new ast::attribute;
        $$ = ret;
    }
    ;

LIST_0
    : line 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_0  line 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;

%%
int line_count = 0;

// 
int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "%5d: %s: syntax error\n", line_count, yytext);
    return 0;
}

// 
int main(int argc, const char *argv[]) {
    extern int yyparse(void);
    extern FILE *yyin;
    
    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "Compilation error \n");
    }
    
    return 0;
}
