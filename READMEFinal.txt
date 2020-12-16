Tanner Williams, Mason Hamilton, Brent Lund
CST 405

This project will display the sections of code generation, 
three address code, its implementation and MIPS Example generation.
It will also display Optimization which will include the unreachable
code and its implementation.  Dead code and its implemenation, and the
Direct Acyclic Graph

Program instructions in makefile:

default:
	bison -dv test.y
	flex test.l
	gcc -o tester test.tab.c lex.yy.c 

clean:
	rm test.tab.c test.tab.h tester lex.yy.c
	ls -l

MIPS is run through our QT Spim. 


Necessary to run:

 - Flex and Bison on Ubuntu
 - All associated files

Resources:
Symbol Table Help:
https://www.tutorialspoint.com/compiler_design/compiler_design_symbol_table.htm


Code Help:
https://steemit.com/utopian-io/@drifter1/writing-a-simple-compiler-on-my-own-passing-information-from-lexer-to-parser

Mudaware M., Compiler Design