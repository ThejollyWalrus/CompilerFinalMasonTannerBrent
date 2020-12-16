%{
#include "symbol.c"
#include "TheTree.c"
#include "TheTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYDEBUG 1


extern FILE *yyin;
extern FILE *yyout;
extern int lineno;

extern int yylex();

struct FuncDecAST* tempFuncDecAST;
void add_to_names(struct list_t *entry);
struct list_t **names;
int namesCount = 0;

int open = 1;

void yyerror (const char *s) {
	fprintf(stderr, "There is an error at linerere %i: %s\n", lineno, s);
}
extern int yydebug;
%}

%union{
	struct list_t* symtab_item;
    	  int number;
	struct AST* node;
	  int intVal;
	  char* strVal;
	struct Param parameter;
	union Value val;
	//int val;
	  
}


%token <val> NUM OTHER SEMICOLON IF WRITELN WRITE WHILE ELSE RETURNS BREAK READ COMMA COLON
%token <val> LPARN RPARN LEFTBRAC RIGHTBRAC LEFTCURLY RIGHTCURLY
%token <val> ADD MINUS MUL DIV EQUAL EQUALS NOTEQUAL LESSTHAN LESSTHANOREQ GREATERTHAN GREATERTHANOREQ AND OR EXCLAMATIONPT POWER

%token <symtab_item> ID
%token <intVal> CHAR INT DOUBLE BOOL FLOAT
%token <strVal> STRING

%type <intVal> Type
%right EQUAL
//%left ADD MINUS MUL DIV EQUALS NOTEQUAL LESSTHAN LESSTHANOREQ GREATERTHAN GREATERTHANOREQ AND OR EXCLAMATIONPT POWER
//%left LPARN RPARN LEFTBRAC RIGHTBRAC LEFTCURLY RIGHTCURLY
%left COMMA
%left OR
%left AND
%left EQUALS
%left NOTEQUAL
%left LESSTHAN LESSTHANOREQ GREATERTHAN GREATERTHANOREQ 
%left ADD MINUS MUL DIV
//%left LPARN RPARN LEFTBRAC RIGHTBRAC

%type <node> Program VarDeclList VarDecl X1 FunDeclList X2 FunDecl ParamDecList ParamDeclListTail X3 X4 Block StmtList X5 Stmt Astmt Expr X6 X7 Primary X8 ExprList ExprListTail X9 
%type <parameter> ParamDecl 


%start Program




%%

Program: 
	VarDeclList {EnterAST($1); } 
	|FunDeclList {EnterAST($1);}
;

VarDeclList: %empty {printf("This should work\n");}  
	|VarDecl  VarDeclList{
	
	//$$ = newDecls(NULL, 0, $1);
	//struct DeclsAST *tempAST = (struct DeclsAST*)$1;
	//$$ = newDecls(tempAST->decls, tempAST->declsCount, $2);
	}
	//|VarDecl{$$ = newDecls(NULL, 0, $1);}
	| FunDeclList //{EnterAST($1);}
;

VarDecl: Type ID {add_to_names($2);}X1{
	
	$$ = newDecl($1, names, namesCount);
	namesCount = 0;

	struct DeclAST *tempDeclAST =(struct DeclAST*)$$;
	
	if($4 != NULL){
	struct ConstAST* tempConstAST =(struct ConstAST*)$4;
	//tempConstAST->val->$4.ival;
	//tempConstAST->dataType->TYPE_INT;
		//$$ = newConst(tempConstAST->dataType->TYPE_INT, tempConstAST->val->$4.ival);
		
		}

}
;

X1: SEMICOLON {$$=NULL;}
	| LEFTBRAC NUM RIGHTBRAC SEMICOLON// { $$ = $2.ival;  }
;

FunDeclList: FunDecl X2 {$$=$1;}
;

X2: %empty{printf(" ");}
 |FunDeclList {}
	
;

FunDecl:   Type ID LPARN { incrScope();} ParamDecList RPARN Block {$$=$7;}
;

ParamDecList: {}
	| ParamDeclListTail 
;

ParamDeclListTail: ParamDecl X3 {}
;

ParamDecl:  Type ID X4 {declare = 0;}
;

X3: {}
	| COMMA ParamDeclListTail {printf("ParamDeclListTail \n");}
;
X4: {}
	| LEFTBRAC RIGHTBRAC {printf("X4 \n");}
;	
Block: LEFTCURLY {open = 1;} VarDeclList StmtList RIGHTCURLY {printf("Block \n"); $$ = $4;  open = 1;}
;

StmtList: Stmt X5 { struct StmtsAST* tempStmtsAST = (struct StmtsAST*)$1;
				$$ = newStmts(tempStmtsAST->stmts, tempStmtsAST->stmtsCount, $2);}
;

X5: {printf(" ");}
	| StmtList {//struct StmtsAST* tempStmtsAST = (struct StmtsAST*)$1;
				//$$ = newStmts(tempStmtsAST->stmts, tempStmtsAST->stmtsCount, $1);}
	}
;

Stmt: Astmt SEMICOLON {$$ = $1;}
	| RETURNS Expr SEMICOLON //{tempFuncDecAST->returnNode = newNodeReturn(tempFuncDecAST->returnType, $2);}
	| READ ID SEMICOLON {$$ = newRead($2, $2->val);}
	| WRITE Expr SEMICOLON {printf("writing CHECK\n");} 
	| WRITELN SEMICOLON {}
	| BREAK SEMICOLON {}
	| IF LPARN Expr RPARN Stmt ELSE Stmt {printf("IF Stmt \n");}
	| WHILE LPARN Expr RPARN Stmt {printf("WHILE Stmt \n");}
	| Block {$$ = $1;}
;
/* WORKS FINE */

Astmt: ID X7 {$$ = $2;}
;

Expr: Primary X6 {$$ = $1;}
	| UnaryOp Expr X6 {}
;

X6: {}
	| BinOp Expr X6 {}
;
X7: EQUAL Expr X6 {$$ = $2;}
	| LEFTBRAC Expr RIGHTBRAC EQUAL Expr X6 {}
;

Primary: ID X8 { $$=$2;}
	| NUM //{$$=$1; }
	| LPARN Expr RPARN {$$ = $2;}
;

X8: {}
	| LPARN ExprList RPARN {}
	| LEFTBRAC Expr RIGHTBRAC {}
;

ExprList: {}
	| ExprListTail {}
;

ExprListTail: Expr X9
;

X9: {}
	| COMMA ExprListTail {}

UnaryOp: MINUS
		| EXCLAMATIONPT
;

BinOp: ADD
	| MINUS
	| MUL
	| DIV
	| EQUALS
	| NOTEQUAL
	| GREATERTHAN
	| GREATERTHANOREQ
	| LESSTHAN
	| LESSTHANOREQ
	| AND
	| OR
	

;
Type:	INT { setType(1); $$ = TYPE_INT;}
	|CHAR {setType(8); $$ = TYPE_CHAR;}
	
%%


int main(int argc, char *argv[])
{	
	InitHashTable();
	
	yyin = fopen(argv[1], "r");
	

	yyparse();

	fclose(yyin);
	
	printf("Parsing finished!");
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");

	


	
	build_symtab(yyout);
	
	fclose(yyout);

	return 0;
} 


void add_to_names(struct list_t *entry){
	// first entry
	if(namesCount == 0){
		namesCount = 1;
		names = (struct list_t **) malloc( 1 * sizeof(struct list_t *));
		names[0] = entry;
	}
	// general case
	else{
		namesCount++;
		names = (struct list_t **) realloc(names, namesCount * sizeof(struct list_t *));
		names[namesCount - 1] = entry;		
	}
}

