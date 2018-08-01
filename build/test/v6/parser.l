%{
#define MAX_TOKEN_LEN 2048

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"


#ifdef YYDEBUG
extern int yydebug;
#endif

extern int line_count;

int
yywrap(void)
{
    return 1;
}


char *dst;


%}



%x IN_STRING
%x IN_COMMENT
%x IN_LINECOMMENT
%x IN_ESCAPED_IDENTIFIER
%%


[ \t\r] {

}
\n {
	++line_count;
}



\"       {
	dst = yylval.token_str;
	BEGIN(IN_STRING);
}
<IN_STRING>[^\"\n] {
	*dst++ = *yytext;
}
<IN_STRING>\n {
	fprintf(stderr, 
	"cannot include new line character inside string; use escaped sequence insead. \n");
	exit(1);
}
<IN_STRING>"\"" {
	*dst = '\0';
	BEGIN(INITIAL);
	return SV_STRING;
}

"/*" {
	BEGIN(IN_COMMENT);
}
<IN_COMMENT>"*/" {
	BEGIN(INITIAL);
}
<IN_COMMENT>[^\n] {

}
<IN_COMMENT>\n {
	++line_count;
}

"//" {
	BEGIN(IN_LINECOMMENT);
}
<IN_LINECOMMENT>[^\n] {
	;
}
<IN_LINECOMMENT>\n {
	BEGIN(INITIAL);
	++line_count;
}

";" return TOKEN_0;
"library" return TOKEN_1;
"," return TOKEN_2;
"-incdir" return TOKEN_3;
"include" return TOKEN_4;
"endmodule" return TOKEN_5;
":" return TOKEN_6;
"extern" return TOKEN_7;
"module" return TOKEN_8;
"macromodule" return TOKEN_9;
"endinterface" return TOKEN_10;
"interface" return TOKEN_11;
"(" return TOKEN_12;
".*" return TOKEN_13;
")" return TOKEN_14;
"endprogram" return TOKEN_15;
"program" return TOKEN_16;
"checker" return TOKEN_17;
"endchecker" return TOKEN_18;
"virtual" return TOKEN_19;
"class" return TOKEN_20;
"extends" return TOKEN_21;
"implements" return TOKEN_22;
"endclass" return TOKEN_23;
"package" return TOKEN_24;
"endpackage" return TOKEN_25;
"timeunit" return TOKEN_26;
"/" return TOKEN_27;
"timeprecision" return TOKEN_28;
"#" return TOKEN_29;
"type" return TOKEN_30;
"." return TOKEN_31;
"{" return TOKEN_32;
"}" return TOKEN_33;
"input" return TOKEN_34;
"output" return TOKEN_35;
"inout" return TOKEN_36;
"ref" return TOKEN_37;
"=" return TOKEN_38;
"dollarsign_fatal" return TOKEN_39;
"dollarsign_error" return TOKEN_40;
"dollarsign_warning" return TOKEN_41;
"dollarsign_info" return TOKEN_42;
"0" return TOKEN_43;
"1" return TOKEN_44;
"2" return TOKEN_45;
"default" return TOKEN_46;
"clocking" return TOKEN_47;
"disable" return TOKEN_48;
"iff" return TOKEN_49;
"defparam" return TOKEN_50;
"bind" return TOKEN_51;
"config" return TOKEN_52;
"endconfig" return TOKEN_53;
"design" return TOKEN_54;
"instance" return TOKEN_55;
"cell" return TOKEN_56;
"liblist" return TOKEN_57;
"use" return TOKEN_58;
"forkjoin" return TOKEN_59;
"rand" return TOKEN_60;
"const" return TOKEN_61;
"pure" return TOKEN_62;
"function" return TOKEN_63;
"new" return TOKEN_64;
"static" return TOKEN_65;
"protected" return TOKEN_66;
"local" return TOKEN_67;
"randc" return TOKEN_68;
"super" return TOKEN_69;
"endfunction" return TOKEN_70;
"constraint" return TOKEN_71;
"solve" return TOKEN_72;
"before" return TOKEN_73;
"soft" return TOKEN_74;
"->" return TOKEN_75;
"if" return TOKEN_76;
"else" return TOKEN_77;
"foreach" return TOKEN_78;
"[" return TOKEN_79;
"]" return TOKEN_80;
"unique" return TOKEN_81;
":=" return TOKEN_82;
":/" return TOKEN_83;
"localparam" return TOKEN_84;
"parameter" return TOKEN_85;
"specparam" return TOKEN_86;
"var" return TOKEN_87;
"import" return TOKEN_88;
"::" return TOKEN_89;
"*" return TOKEN_90;
"export" return TOKEN_91;
"*::*" return TOKEN_92;
"genvar" return TOKEN_93;
"vectored" return TOKEN_94;
"scalared" return TOKEN_95;
"interconnect" return TOKEN_96;
"typedef" return TOKEN_97;
"enum" return TOKEN_98;
"struct" return TOKEN_99;
"union" return TOKEN_100;
"nettype" return TOKEN_101;
"with" return TOKEN_102;
"automatic" return TOKEN_103;
"string" return TOKEN_104;
"packed" return TOKEN_105;
"chandle" return TOKEN_106;
"event" return TOKEN_107;
"byte" return TOKEN_108;
"shortint" return TOKEN_109;
"int" return TOKEN_110;
"longint" return TOKEN_111;
"integer" return TOKEN_112;
"time" return TOKEN_113;
"bit" return TOKEN_114;
"logic" return TOKEN_115;
"reg" return TOKEN_116;
"shortreal" return TOKEN_117;
"real" return TOKEN_118;
"realtime" return TOKEN_119;
"supply0" return TOKEN_120;
"supply1" return TOKEN_121;
"tri" return TOKEN_122;
"triand" return TOKEN_123;
"trior" return TOKEN_124;
"trireg" return TOKEN_125;
"tri0" return TOKEN_126;
"tri1" return TOKEN_127;
"uwire" return TOKEN_128;
"wire" return TOKEN_129;
"wand" return TOKEN_130;
"wor" return TOKEN_131;
"signed" return TOKEN_132;
"unsigned" return TOKEN_133;
"void" return TOKEN_134;
"tagged" return TOKEN_135;
"highz1" return TOKEN_136;
"highz0" return TOKEN_137;
"strong0" return TOKEN_138;
"pull0" return TOKEN_139;
"weak0" return TOKEN_140;
"strong1" return TOKEN_141;
"pull1" return TOKEN_142;
"weak1" return TOKEN_143;
"small" return TOKEN_144;
"medium" return TOKEN_145;
"large" return TOKEN_146;
"1step" return TOKEN_147;
"PATHPULSEdollarsign_" return TOKEN_148;
"dollarsign_" return TOKEN_149;
"task" return TOKEN_150;
"DPI-C" return TOKEN_151;
"DPI" return TOKEN_152;
"context" return TOKEN_153;
"endtask" return TOKEN_154;
"+" return TOKEN_155;
"++" return TOKEN_156;
"-" return TOKEN_157;
"--" return TOKEN_158;
"**" return TOKEN_159;
"%" return TOKEN_160;
"==" return TOKEN_161;
"!=" return TOKEN_162;
"<" return TOKEN_163;
"<=" return TOKEN_164;
">" return TOKEN_165;
">=" return TOKEN_166;
"modport" return TOKEN_167;
"assert" return TOKEN_168;
"property" return TOKEN_169;
"assume" return TOKEN_170;
"cover" return TOKEN_171;
"expect" return TOKEN_172;
"sequence" return TOKEN_173;
"restrict" return TOKEN_174;
"endproperty" return TOKEN_175;
"strong" return TOKEN_176;
"weak" return TOKEN_177;
"not" return TOKEN_178;
"or" return TOKEN_179;
"and" return TOKEN_180;
"|->" return TOKEN_181;
"|=>" return TOKEN_182;
"case" return TOKEN_183;
"endcase" return TOKEN_184;
"#-#" return TOKEN_185;
"#=#" return TOKEN_186;
"nexttime" return TOKEN_187;
"s_nexttime" return TOKEN_188;
"always" return TOKEN_189;
"s_always" return TOKEN_190;
"s_eventually" return TOKEN_191;
"until" return TOKEN_192;
"s_until" return TOKEN_193;
"until_with" return TOKEN_194;
"s_until_with" return TOKEN_195;
"implies" return TOKEN_196;
"accept_on" return TOKEN_197;
"reject_on" return TOKEN_198;
"sync_accept_on" return TOKEN_199;
"sync_reject_on" return TOKEN_200;
"endsequence" return TOKEN_201;
"untyped" return TOKEN_202;
"intersect" return TOKEN_203;
"first_match" return TOKEN_204;
"throughout" return TOKEN_205;
"within" return TOKEN_206;
"##" return TOKEN_207;
"[*]" return TOKEN_208;
"[+]" return TOKEN_209;
"[*" return TOKEN_210;
"[=" return TOKEN_211;
"[->" return TOKEN_212;
"dist" return TOKEN_213;
"let" return TOKEN_214;
"covergroup" return TOKEN_215;
"endgroup" return TOKEN_216;
"option" return TOKEN_217;
"type_option" return TOKEN_218;
"sample" return TOKEN_219;
"@@" return TOKEN_220;
"begin" return TOKEN_221;
"end" return TOKEN_222;
"coverpoint" return TOKEN_223;
"wildcard" return TOKEN_224;
"bins" return TOKEN_225;
"illegal_bins" return TOKEN_226;
"ignore_bins" return TOKEN_227;
"=>" return TOKEN_228;
"cross" return TOKEN_229;
"!" return TOKEN_230;
"&&" return TOKEN_231;
"||" return TOKEN_232;
"matches" return TOKEN_233;
"binsof" return TOKEN_234;
"pulldown" return TOKEN_235;
"pullup" return TOKEN_236;
"cmos" return TOKEN_237;
"rcmos" return TOKEN_238;
"bufif0" return TOKEN_239;
"bufif1" return TOKEN_240;
"notif0" return TOKEN_241;
"notif1" return TOKEN_242;
"nmos" return TOKEN_243;
"pmos" return TOKEN_244;
"rnmos" return TOKEN_245;
"rpmos" return TOKEN_246;
"nand" return TOKEN_247;
"nor" return TOKEN_248;
"xor" return TOKEN_249;
"xnor" return TOKEN_250;
"buf" return TOKEN_251;
"tranif0" return TOKEN_252;
"tranif1" return TOKEN_253;
"rtranif0" return TOKEN_254;
"rtranif1" return TOKEN_255;
"tran" return TOKEN_256;
"rtran" return TOKEN_257;
"generate" return TOKEN_258;
"endgenerate" return TOKEN_259;
"for" return TOKEN_260;
"primitive" return TOKEN_261;
"endprimitive" return TOKEN_262;
"table" return TOKEN_263;
"endtable" return TOKEN_264;
"initial" return TOKEN_265;
"1'b0" return TOKEN_266;
"1'b1" return TOKEN_267;
"1'bx" return TOKEN_268;
"1'bX" return TOKEN_269;
"1'B0" return TOKEN_270;
"1'B1" return TOKEN_271;
"1'Bx" return TOKEN_272;
"1'BX" return TOKEN_273;
"x" return TOKEN_274;
"X" return TOKEN_275;
"?" return TOKEN_276;
"b" return TOKEN_277;
"B" return TOKEN_278;
"r" return TOKEN_279;
"R" return TOKEN_280;
"f" return TOKEN_281;
"F" return TOKEN_282;
"p" return TOKEN_283;
"P" return TOKEN_284;
"n" return TOKEN_285;
"N" return TOKEN_286;
"assign" return TOKEN_287;
"alias" return TOKEN_288;
"always_comb" return TOKEN_289;
"always_latch" return TOKEN_290;
"always_ff" return TOKEN_291;
"final" return TOKEN_292;
"+=" return TOKEN_293;
"-=" return TOKEN_294;
"*=" return TOKEN_295;
"/=" return TOKEN_296;
"%=" return TOKEN_297;
"&=" return TOKEN_298;
"|=" return TOKEN_299;
"^=" return TOKEN_300;
"<<=" return TOKEN_301;
">>=" return TOKEN_302;
"<<<=" return TOKEN_303;
">>>=" return TOKEN_304;
"deassign" return TOKEN_305;
"force" return TOKEN_306;
"release" return TOKEN_307;
"fork" return TOKEN_308;
"join" return TOKEN_309;
"join_any" return TOKEN_310;
"join_none" return TOKEN_311;
"repeat" return TOKEN_312;
"@" return TOKEN_313;
"return" return TOKEN_314;
"break" return TOKEN_315;
"continue" return TOKEN_316;
"wait" return TOKEN_317;
"wait_order" return TOKEN_318;
"->>" return TOKEN_319;
"unique0" return TOKEN_320;
"priority" return TOKEN_321;
"&&&" return TOKEN_322;
"inside" return TOKEN_323;
"casex" return TOKEN_324;
"casez" return TOKEN_325;
"randcase" return TOKEN_326;
"'" return TOKEN_327;
"forever" return TOKEN_328;
"while" return TOKEN_329;
"do" return TOKEN_330;
"#0" return TOKEN_331;
"endclocking" return TOKEN_332;
"global" return TOKEN_333;
"randsequence" return TOKEN_334;
"|" return TOKEN_335;
"specify" return TOKEN_336;
"endspecify" return TOKEN_337;
"pulsestyle_onevent" return TOKEN_338;
"pulsestyle_ondetect" return TOKEN_339;
"showcancelled" return TOKEN_340;
"noshowcancelled" return TOKEN_341;
"*>" return TOKEN_342;
"posedge" return TOKEN_343;
"negedge" return TOKEN_344;
"edge" return TOKEN_345;
"ifnone" return TOKEN_346;
"dollarsign_setup" return TOKEN_347;
"dollarsign_hold" return TOKEN_348;
"dollarsign_setuphold" return TOKEN_349;
"dollarsign_recovery" return TOKEN_350;
"dollarsign_removal" return TOKEN_351;
"dollarsign_recrem" return TOKEN_352;
"dollarsign_skew" return TOKEN_353;
"dollarsign_timeskew" return TOKEN_354;
"dollarsign_fullskew" return TOKEN_355;
"dollarsign_period" return TOKEN_356;
"dollarsign_width" return TOKEN_357;
"dollarsign_nochange" return TOKEN_358;
"01" return TOKEN_359;
"10" return TOKEN_360;
"z" return TOKEN_361;
"Z" return TOKEN_362;
"~" return TOKEN_363;
"===" return TOKEN_364;
"!==" return TOKEN_365;
"'b0" return TOKEN_366;
"'b1" return TOKEN_367;
"'B0" return TOKEN_368;
"'B1" return TOKEN_369;
">>" return TOKEN_370;
"<<" return TOKEN_371;
"+:" return TOKEN_372;
"-:" return TOKEN_373;
"std::" return TOKEN_374;
"randomize" return TOKEN_375;
"null" return TOKEN_376;
"this" return TOKEN_377;
"local::" return TOKEN_378;
"s" return TOKEN_379;
"ms" return TOKEN_380;
"us" return TOKEN_381;
"ns" return TOKEN_382;
"ps" return TOKEN_383;
"fs" return TOKEN_384;
"&" return TOKEN_385;
"~&" return TOKEN_386;
"~|" return TOKEN_387;
"^" return TOKEN_388;
"~^" return TOKEN_389;
"^~" return TOKEN_390;
"==?" return TOKEN_391;
"!=?" return TOKEN_392;
">>>" return TOKEN_393;
"<<<" return TOKEN_394;
"<->" return TOKEN_395;
"'0" return TOKEN_396;
"'1" return TOKEN_397;
"(*" return TOKEN_398;
"*)" return TOKEN_399;
"dollarsign_unit" return TOKEN_400;
[0-9]+ {
	strcpy(yylval.token_str, yytext);
	return SV_INTEGER;
}
[a-zA-Z_][a-zA-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return SV_IDENTIFIER;
}



"\\" {
	dst = yylval.token_str;
	BEGIN(IN_ESCAPED_IDENTIFIER);
}
<IN_ESCAPED_IDENTIFIER>[ \r\t] {
	*dst = '\0';
	BEGIN(INITIAL);
	return SV_ESCAPED_IDENTIFIER;
}
<IN_ESCAPED_IDENTIFIER>\n {
	*dst = '\0';
	++line_count;
	BEGIN(INITIAL);
	return SV_ESCAPED_IDENTIFIER;
}
<IN_ESCAPED_IDENTIFIER>[^ \r\t\n] {
	*dst++ = *yytext;
}



[1-9][0-9_]* {
	strcpy(yylval.token_str, yytext);
	return SV_UNSIGNED_NUMBER;
}
[1-9][0-9_]*'[sS]?[dD][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_DECIMAL_NUMBER;
}
[1-9][0-9_]*'[sS]?[oO][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_OCTAL_NUMBER;
}
[1-9][0-9_]*'[sS]?[bB][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_BINARY_NUMBER;
}
[1-9][0-9_]*'[sS]?[hH][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_HEX_NUMBER;
}



[1-9][0-9_*]"."[0-9]* {
	strcpy(yylval.token_str, yytext);
	return SV_FIXED_POINT_NUMBER;
}
[1-9][0-9_*]("."[0-9]*)?[eE][+-]?(0-9)+ {
	strcpy(yylval.token_str, yytext);
	return SV_EXPONENTIAL_NUMBER;
}












