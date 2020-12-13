#include <cstdio>
#include <cstdlib>
#include "parser_ast.h"


const char *tab = "    ";


static void print(FILE *out, int level, const std::string &prefix) {
    //for (int i = 0; i < level; ++i) {
    //    fprintf(out, "%s", tab);
    //}
    //fprintf(out, "%s", prefix.c_str());
}



// 
void ast::line_list::describe(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::line_list::describe] \n");
    _list->describe(cs.sub0());
}
// 
void ast::line_list::action(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::line_list::action] \n");
}



//
void ast::line::describe(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::line::describe] \n");
    _expr->describe(cs.sub());
    fprintf(cs.out, "; \n");
}
//
void ast::line::action(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::line::action] \n");
}



//
void ast::expr::describe(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::expr::describe] \n");
    switch (_init_type) {
    case 0:
        print(cs.out, cs.level, "[ast::expr::describe] 0 \n");
        _expr->describe(cs.sub());
        _term->describe(cs.sub());
        print(cs.out, cs.level, "[ast::expr::describe] ");
        fprintf(cs.out, "%s ", _op.c_str());
        break;
    case 1:
        print(cs.out, cs.level, "[ast::expr::describe] 1 \n");
        _expr->describe(cs.sub());
        _term->describe(cs.sub());
        print(cs.out, cs.level, "[ast::expr::describe] ");
        fprintf(cs.out, "%s ", _op.c_str());
        break;
    case 2:
        print(cs.out, cs.level, "[ast::expr::describe] 2 \n");
        _term->describe(cs.sub());
        break;
    default:
        print(cs.out, cs.level, "[ast::expr::describe] 3 \n");
        break;
    }
}
//
void ast::expr::action(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::expr::action] \n");
}



//
void ast::term::describe(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::term::describe] \n");
    switch (_init_type) {
    case 0:
        print(cs.out, cs.level, "[ast::term::describe] 0 \n");
        _term->describe(cs.sub());
        _primary->describe(cs.sub());
        print(cs.out, cs.level, "[ast::term::describe] ");
        fprintf(cs.out, "%s ", _op.c_str());
        break;
    case 1:
        print(cs.out, cs.level, "[ast::term::describe] 1 \n");
        _term->describe(cs.sub());
        _primary->describe(cs.sub());
        print(cs.out, cs.level, "[ast::term::describe] ");
        fprintf(cs.out, "%s ", _op.c_str());
        break;
    case 2:
        print(cs.out, cs.level, "[ast::term::describe] 2 \n");
        _primary->describe(cs.sub());
        break;
    default:
        print(cs.out, cs.level, "[ast::term::describe] 3 \n");
        break;
    }
}
//
void ast::term::action(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::term::action] \n");
}



//
void ast::primary::describe(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::primary::describe] \n");
    switch (_init_type) {
    case 0:
        print(cs.out, cs.level, "[ast::primary::describe] 0 \n");
        fprintf(cs.out, "%d ", _number);
        break;
    case 1:
        print(cs.out, cs.level, "[ast::primary::describe] 1 \n");
        fprintf(cs.out, "%d ", _number);
        break;
    case 2:
        print(cs.out, cs.level, "[ast::primary::describe] 2 \n");
        fprintf(cs.out, "%d ", _number);
        break;
    case 3:
        print(cs.out, cs.level, "[ast::primary::describe] 3 \n");
        fprintf(cs.out, "%d ", _number);
        break;
    case 4:
        print(cs.out, cs.level, "[ast::primary::describe] 4 \n");
        fprintf(cs.out, "%d ", _number);
        break;
    case 5:
        print(cs.out, cs.level, "[ast::primary::describe] 5 \n");
        fprintf(cs.out, "%s ", _string.c_str());
        break;
    case 6:
        print(cs.out, cs.level, "[ast::primary::describe] 6 \n");
        _attribute->describe(cs.sub());
        break;
    case 7:
        print(cs.out, cs.level, "[ast::primary::describe] 7 \n");
        _expr->describe(cs.sub());
        break;
    default:
        break;
    }
}
//
void ast::primary::action(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::primary::action] \n");
}



//
void ast::attribute::describe(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::attribute::describe] \n");
}
//
void ast::attribute::action(cs_info &&cs) {
    print(cs.out, cs.level, "[ast::attribute::action] \n");
}



