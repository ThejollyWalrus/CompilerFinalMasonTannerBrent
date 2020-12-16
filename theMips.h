// Mason Hamilton
// Tanner Williams 
// Brent Lund
// CST-405
// Professor Nasser Tadayon

#ifndef THEMIPS_H
#define THEMIPS_H

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"TheTree.h"
#include"symbol.h"
static int count;

FILE* input;
FILE* output;



extern void startMips(struct AST* nn);

extern void exprMips(struct AST* nn);

extern void declsMips(struct DeclsAST* nn);

extern void declMips(struct DeclAST* nn);

extern void paramMips(struct CallParamsAST* nn);

extern void equalEquMips(struct EquAST* nn);

extern void printMips(const char* label, struct list_t* symTab);







#endif