%{
#define MAX_TOKEN_LEN 2048

#include <stdio.h>
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
"pure" return TOKEN_24;
"package" return TOKEN_25;
"endpackage" return TOKEN_26;
"timeunit" return TOKEN_27;
"/" return TOKEN_28;
"timeprecision" return TOKEN_29;
"#" return TOKEN_30;
"type" return TOKEN_31;
"." return TOKEN_32;
"{" return TOKEN_33;
"}" return TOKEN_34;
"input" return TOKEN_35;
"output" return TOKEN_36;
"inout" return TOKEN_37;
"ref" return TOKEN_38;
"=" return TOKEN_39;
"dollarsign_fatal" return TOKEN_40;
"dollarsign_error" return TOKEN_41;
"dollarsign_warning" return TOKEN_42;
"dollarsign_info" return TOKEN_43;
"0" return TOKEN_44;
"1" return TOKEN_45;
"2" return TOKEN_46;
"default" return TOKEN_47;
"clocking" return TOKEN_48;
"disable" return TOKEN_49;
"iff" return TOKEN_50;
"defparam" return TOKEN_51;
"bind" return TOKEN_52;
"config" return TOKEN_53;
"endconfig" return TOKEN_54;
"design" return TOKEN_55;
"instance" return TOKEN_56;
"cell" return TOKEN_57;
"liblist" return TOKEN_58;
"use" return TOKEN_59;
"forkjoin" return TOKEN_60;
"rand" return TOKEN_61;
"const" return TOKEN_62;
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
"endsequence" return TOKEN_176;
"untyped" return TOKEN_177;
"##" return TOKEN_178;
"[*]" return TOKEN_179;
"[+]" return TOKEN_180;
"[*" return TOKEN_181;
"[=" return TOKEN_182;
"[->" return TOKEN_183;
"dist" return TOKEN_184;
"let" return TOKEN_185;
"covergroup" return TOKEN_186;
"endgroup" return TOKEN_187;
"option" return TOKEN_188;
"type_option" return TOKEN_189;
"sample" return TOKEN_190;
"@@" return TOKEN_191;
"begin" return TOKEN_192;
"end" return TOKEN_193;
"coverpoint" return TOKEN_194;
"bins" return TOKEN_195;
"illegal_bins" return TOKEN_196;
"ignore_bins" return TOKEN_197;
"=>" return TOKEN_198;
"cross" return TOKEN_199;
"!" return TOKEN_200;
"&&" return TOKEN_201;
"||" return TOKEN_202;
"matches" return TOKEN_203;
"binsof" return TOKEN_204;
"intersect" return TOKEN_205;
"pulldown" return TOKEN_206;
"pullup" return TOKEN_207;
"cmos" return TOKEN_208;
"rcmos" return TOKEN_209;
"bufif0" return TOKEN_210;
"bufif1" return TOKEN_211;
"notif0" return TOKEN_212;
"notif1" return TOKEN_213;
"nmos" return TOKEN_214;
"pmos" return TOKEN_215;
"rnmos" return TOKEN_216;
"rpmos" return TOKEN_217;
"and" return TOKEN_218;
"nand" return TOKEN_219;
"or" return TOKEN_220;
"nor" return TOKEN_221;
"xor" return TOKEN_222;
"xnor" return TOKEN_223;
"buf" return TOKEN_224;
"not" return TOKEN_225;
"tranif0" return TOKEN_226;
"tranif1" return TOKEN_227;
"rtranif0" return TOKEN_228;
"rtranif1" return TOKEN_229;
"tran" return TOKEN_230;
"rtran" return TOKEN_231;
"generate" return TOKEN_232;
"endgenerate" return TOKEN_233;
"for" return TOKEN_234;
"case" return TOKEN_235;
"endcase" return TOKEN_236;
"primitive" return TOKEN_237;
"endprimitive" return TOKEN_238;
"table" return TOKEN_239;
"endtable" return TOKEN_240;
"initial" return TOKEN_241;
"1'b0" return TOKEN_242;
"1'b1" return TOKEN_243;
"1'bx" return TOKEN_244;
"1'bX" return TOKEN_245;
"1'B0" return TOKEN_246;
"1'B1" return TOKEN_247;
"1'Bx" return TOKEN_248;
"1'BX" return TOKEN_249;
"x" return TOKEN_250;
"X" return TOKEN_251;
"?" return TOKEN_252;
"b" return TOKEN_253;
"B" return TOKEN_254;
"r" return TOKEN_255;
"R" return TOKEN_256;
"f" return TOKEN_257;
"F" return TOKEN_258;
"p" return TOKEN_259;
"P" return TOKEN_260;
"n" return TOKEN_261;
"N" return TOKEN_262;
"assign" return TOKEN_263;
"alias" return TOKEN_264;
"always" return TOKEN_265;
"always_comb" return TOKEN_266;
"always_latch" return TOKEN_267;
"always_ff" return TOKEN_268;
"final" return TOKEN_269;
"+=" return TOKEN_270;
"-=" return TOKEN_271;
"*=" return TOKEN_272;
"/=" return TOKEN_273;
"%=" return TOKEN_274;
"&=" return TOKEN_275;
"|=" return TOKEN_276;
"^=" return TOKEN_277;
"<<=" return TOKEN_278;
">>=" return TOKEN_279;
"<<<=" return TOKEN_280;
">>>=" return TOKEN_281;
"deassign" return TOKEN_282;
"force" return TOKEN_283;
"release" return TOKEN_284;
"fork" return TOKEN_285;
"join" return TOKEN_286;
"join_any" return TOKEN_287;
"join_none" return TOKEN_288;
"repeat" return TOKEN_289;
"@" return TOKEN_290;
"return" return TOKEN_291;
"break" return TOKEN_292;
"continue" return TOKEN_293;
"wait" return TOKEN_294;
"wait_order" return TOKEN_295;
"->>" return TOKEN_296;
"unique0" return TOKEN_297;
"priority" return TOKEN_298;
"&&&" return TOKEN_299;
"inside" return TOKEN_300;
"casex" return TOKEN_301;
"casez" return TOKEN_302;
"randcase" return TOKEN_303;
"'" return TOKEN_304;
"forever" return TOKEN_305;
"while" return TOKEN_306;
"do" return TOKEN_307;
"#0" return TOKEN_308;
"endclocking" return TOKEN_309;
"global" return TOKEN_310;
"randsequence" return TOKEN_311;
"|" return TOKEN_312;
"specify" return TOKEN_313;
"endspecify" return TOKEN_314;
"pulsestyle_onevent" return TOKEN_315;
"pulsestyle_ondetect" return TOKEN_316;
"showcancelled" return TOKEN_317;
"noshowcancelled" return TOKEN_318;
"*>" return TOKEN_319;
"posedge" return TOKEN_320;
"negedge" return TOKEN_321;
"edge" return TOKEN_322;
"ifnone" return TOKEN_323;
"dollarsign_setup" return TOKEN_324;
"dollarsign_hold" return TOKEN_325;
"dollarsign_setuphold" return TOKEN_326;
"dollarsign_recovery" return TOKEN_327;
"dollarsign_removal" return TOKEN_328;
"dollarsign_recrem" return TOKEN_329;
"dollarsign_skew" return TOKEN_330;
"dollarsign_timeskew" return TOKEN_331;
"dollarsign_fullskew" return TOKEN_332;
"dollarsign_period" return TOKEN_333;
"dollarsign_width" return TOKEN_334;
"dollarsign_nochange" return TOKEN_335;
"01" return TOKEN_336;
"10" return TOKEN_337;
"z" return TOKEN_338;
"Z" return TOKEN_339;
"~" return TOKEN_340;
"===" return TOKEN_341;
"!==" return TOKEN_342;
"'b0" return TOKEN_343;
"'b1" return TOKEN_344;
"'B0" return TOKEN_345;
"'B1" return TOKEN_346;
">>" return TOKEN_347;
"<<" return TOKEN_348;
"+:" return TOKEN_349;
"-:" return TOKEN_350;
"std::" return TOKEN_351;
"randomize" return TOKEN_352;
"null" return TOKEN_353;
"this" return TOKEN_354;
"local::" return TOKEN_355;
"s" return TOKEN_356;
"ms" return TOKEN_357;
"us" return TOKEN_358;
"ns" return TOKEN_359;
"ps" return TOKEN_360;
"fs" return TOKEN_361;
"&" return TOKEN_362;
"~&" return TOKEN_363;
"~|" return TOKEN_364;
"^" return TOKEN_365;
"~^" return TOKEN_366;
"^~" return TOKEN_367;
"==?" return TOKEN_368;
"!=?" return TOKEN_369;
">>>" return TOKEN_370;
"<<<" return TOKEN_371;
"<->" return TOKEN_372;
"_" return TOKEN_373;
"e" return TOKEN_374;
"E" return TOKEN_375;
"S" return TOKEN_376;
"d" return TOKEN_377;
"D" return TOKEN_378;
"o" return TOKEN_379;
"O" return TOKEN_380;
"h" return TOKEN_381;
"H" return TOKEN_382;
"3" return TOKEN_383;
"4" return TOKEN_384;
"5" return TOKEN_385;
"6" return TOKEN_386;
"7" return TOKEN_387;
"8" return TOKEN_388;
"9" return TOKEN_389;
"a" return TOKEN_390;
"c" return TOKEN_391;
"A" return TOKEN_392;
"C" return TOKEN_393;
"'0" return TOKEN_394;
"'1" return TOKEN_395;
"(*" return TOKEN_396;
"*)" return TOKEN_397;
"dollarsign_unit" return TOKEN_398;

[0-9]+ {
	strcpy(yylval.token_str, yytext);
	return SV_INTEGER;
}
[a-zA-Z_][a-zA-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return IDENTIFIER;
}


