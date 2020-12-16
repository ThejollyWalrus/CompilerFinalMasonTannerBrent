
%{
//Mason Hamilton
//CST-405


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol.h"
#include "TheTree.h"
#include "TheParser.tab.h"
extern FILE *yyin;
extern FILE *yyout;

extern int yywrap();

int lineno = 0;
int goBack = 1;
int on  = 1;


int enter = 1;

/*


void deadCode(list_t* checkNode){
if(checkNode == NULL){
printf("empty node\n");
}
else{
if(checkNode->Scope == 1){

	if(checkNode->next->Scope == 0){
printf("Bad code->\n\n");}
}
else if(checkNode->Scope == 0){
printf("Bad code->\n\n");
}
return;
}


*/
void switcher(int ter){
if(ter == 2){on = 2;}
};


void badCode(int input){
if(input == 2){
printf("Bad code ->\n\n");
printf("Unreachable at line: %d: ", lineno);

goBack = 2;
return;
}
};

void spotCode(int insert){
if(insert == 2){
	printf(" '%s' ", yytext);
	}
};

void ret_print(char *token_type);



%}

%x ML_COMMENT

alpha     [a-zA-Z]+
digit     [0-9]+
alnum     {alpha}|{digit}
print     [ -~]

ID        {alpha}+{alnum}*
STRING    \"{print}*\"

%%



return		{enter = 2; return RETURNS;}
read		{badCode(on); spotCode(on); return READ;}
write		{spotCode(on); return WRITE;}
writeln		{spotCode(on); return WRITELN;}
break		{enter = 2; return BREAK;}
if			{ spotCode(on); return IF;}
while		{spotCode(on); return WHILE;}
else		{spotCode(on); return ELSE;}

"("		{return LPARN;}
")"	 	{return RPARN;}

"{"		{on = 1; return LEFTCURLY;} 
"}" 		{enter = 1; on = 1;return RIGHTCURLY;} 

"["		{return LEFTBRAC;} 
"]" 		{return RIGHTBRAC;} 

"=" 		{spotCode(on); return EQUAL;}
"+" 		{spotCode(on); return ADD;}
"-" 		{spotCode(on); return MINUS;}
"*" 		{spotCode(on); return MUL;}
"/" 		{spotCode(on); return DIV;}
"^" 		{return POWER;}

">"		{spotCode(on); return GREATERTHAN;}
"<"		{spotCode(on); return LESSTHAN;}
"<="		{spotCode(on); return LESSTHANOREQ;}
">="		{spotCode(on); return GREATERTHANOREQ;}
"=="		{spotCode(on); return EQUALS;}
"!="		{spotCode(on); return NOTEQUAL;}
"&&"		{spotCode(on); return AND;}
"||"		{spotCode(on); return OR;}


";" 		{spotCode(on); switcher(enter); goBack = 1;  printf("\n"); return SEMICOLON;}
"," 		{return COMMA;}
":" 		{return COLON;}
"!" 		{return EXCLAMATIONPT;}



"char"		{return CHAR;}
"int"		{badCode(on);  return INT;}
"bool"		{return BOOL;}
"double" 	{return DOUBLE;}
"float" 	{return FLOAT;}
\n						        {lineno++; }

{ID}    {
		if(goBack == 1){
		badCode(on);};
		if(on == 2){
			printf("'%s'", yytext);
			};
        // insert identifier into symbol table
		//lineno++;
		if(on == 1){
        Insert_v(yytext, strlen(yytext), lineno);
        yylval.symtab_item = LookUp(yytext);
		}
        return ID;
        }

{digit} { spotCode(on); return NUM;}
		/*
{STRING}    { yylval.strVal = malloc(yyleng * sizeof(char));
              strcpy(yylval.strVal, yytext);  return STRING; }
			*/  





%%
int yywrap() {return (1);}