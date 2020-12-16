//Mason Hamilton Brent Lund Tanner Williams 
//CST-405

#ifndef THETREE_C
#define THETREE_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TheTree.h"


struct AST* newNode(enum NodeType Type, struct AST* left, struct AST* right) {
	struct AST* nn = malloc(sizeof(struct AST));
	nn->type = Type;
	nn->left = left;
	nn->right = right;

	return nn;
}


struct AST* newDecls(struct AST** decls, int declsCount, struct AST* declaration) {
	struct DeclsAST* v = malloc(sizeof(struct DeclsAST));

	v->type = Decls;

	if (declaration == NULL) {
		decls = (struct AST**)malloc(sizeof(struct AST*));
		decls[0] = declaration;
		declsCount = 1;
	}
	else {
		decls = (struct AST**)realloc(decls, (declsCount + 1) * sizeof(struct AST*));
		decls[declsCount] = declaration;
		declsCount++;
	}

	v->decls = decls;
	v->declsCount = declsCount;

	return(struct AST*)v;
}

struct AST* newDecl(int dataType, struct list_t** names, int namesCount) {
	struct DeclAST* v = malloc(sizeof(struct DeclAST));
	v->type = Decl;
	v->dataType = dataType;
	v->names = names;
	v->namesCount = namesCount;

	return(struct AST*)v;
}


struct AST* newConst(int dataType, union Value val) {
	struct ConstAST* nn = malloc(sizeof(struct ConstAST));

	nn->type = Const;
	nn->dataType = dataType;
	nn->val = val;


	return(struct AST*)nn;
}

struct AST* newStmts(struct AST** stmts, int stmtsCount, struct AST* stmt) {
	struct StmtsAST* nn = malloc(sizeof(struct StmtsAST));
	nn->type = Stmts;

	if (stmts == NULL) {
		stmts = (struct AST**)malloc(sizeof(struct AST*));
		stmts[0] = stmt;
		stmtsCount = 1;
	}
	else {
		stmts = (struct AST**) realloc (stmts, (stmtsCount + 1) * sizeof(struct AST*));
		stmts[stmtsCount] = stmt;
		stmtsCount++;
	}

	nn->stmts = stmts;
	nn->stmtsCount = stmtsCount;

	return(struct AST*)nn;
}


struct AST* newIf(struct AST* condition, struct AST* ifSec, struct AST* elseSec){

	struct IfAST* nn = malloc(sizeof(struct IfAST));
	
	nn->type = Ifs;
	nn->condition = condition;
	nn->ifSec = ifSec;
	nn->elseSec = elseSec;
	
	return (struct AST*)nn;

	

}

struct AST* newWhile(struct AST* condition, struct AST* whileSec) {
	struct WhileAST* nn = malloc(sizeof(struct WhileAST));

	nn->type = Whiles;
	nn->condition = condition;
	nn->whileSec = whileSec;

	return (struct AST*)nn;
}

struct AST* newAssign(struct list_t* entry, struct AST* assignVal) {
	struct AssignAST* nn = malloc(sizeof(struct AssignAST));

	nn->type = Assign;
	nn->entry = entry;
	nn->assignVal = assignVal;

	return(struct AST*)nn;
}

struct AST* newSimple(int statmentType) {
	struct SimpleAST* nn = malloc(sizeof(struct SimpleAST));
	nn->type = Simples;
	nn->statmentType = statmentType;
	return(struct AST*)nn;

}

struct AST* newFuncCall(struct list_t* entry, struct AST** params, int NumParams) {
	struct FuncCallAST* nn = malloc(sizeof(struct FuncCallAST));
	nn->type = FuncCall;
	nn->entry = entry;
nn->params = params;
nn->numParams = NumParams;

return(struct AST*)nn;
}

struct AST* newParamsCall(struct AST** params, int numParam, struct AST* param) {
	struct CallParamsAST* nn = malloc(sizeof(struct CallParamsAST));
	nn->type = ParamCall;
	if (params == NULL) {
		params = (struct AST**)malloc(sizeof(struct AST*));
		params[0] = param;
		numParam = 1;
	}

	else {
		params = (struct AST**)realloc(params, (numParam + 1) * sizeof(struct AST*));
		params[numParam] = param;
		numParam++;
	}

	nn->params = params;
	nn->numParams = numParam;

	return(struct AST*)nn;
}

struct AST* newArithm(enum opArithm op, struct AST* left, struct AST* right) {
	struct ArithmAST* nn = malloc(sizeof(struct ArithmAST));
	nn->type = Arithm;
	nn->op = op;
	nn->left = left;
	nn->right = right;

	return(struct AST*)nn;
}

struct AST* newBool(enum opBool op, struct AST* left, struct AST* right) {
	struct BoolAST* nn = malloc(sizeof(struct BoolAST));
	nn->type = Bools;
	nn->op = op;
	nn->left = left;
	nn->right = right;

	return (struct AST*)nn;

}

struct AST* newRel(enum opRel op, struct AST* left, struct AST* right) {
	struct RelAST* nn = malloc(sizeof(struct RelAST));
	nn->type = Relat;
	nn->op = op;
	nn->left = left;
	nn->right = right;

	return (struct AST*)nn;
}

struct AST* newEqu(enum opEqu op, struct AST* left, struct AST* right) {
	struct EquAST* nn = malloc(sizeof(struct EquAST));
	nn->type = Equ;
	nn->op = op;
	nn->left = left;
	nn->right = right;
	return(struct AST*)nn;

}

struct AST* newRef(struct list_t* entry) {
	struct RefAST* nn = malloc(sizeof(struct RefAST));
	nn->type = Ref;
	nn->entry = entry;

	return (struct AST*)nn;
}

struct AST* newFuncDecls(struct AST** funcDecls, int funcDeclsCount, struct AST* funcDecl) {
	struct FuncDeclsAST* nn = malloc(sizeof(struct FuncDeclsAST));

	nn->type = FuncDecls;
	if (funcDecls == NULL) {
		funcDecls = (struct AST**)malloc(sizeof(struct AST*));
		funcDecls[0] = funcDecl;
		funcDeclsCount = 1;
	}

	else {
		funcDecls = (struct AST**)realloc(funcDecls, (funcDeclsCount + 1) * sizeof(struct AST*));
		funcDecls[funcDeclsCount] = funcDecl;
		funcDeclsCount++;
	}

	nn->funcDecls = funcDecls;
	nn->funcDeclCount = funcDeclsCount;
	
	return(struct AST*)nn;


}

struct AST* newFunDec(int retType, struct list_t* entry){
	struct FuncDecAST* nn = malloc(sizeof(struct FuncDecAST));
	nn->type = FuncDecl;
	nn->returnType = retType;
	nn->entry = entry;

	return(struct AST*)nn;
}

struct AST* newReturnType(int retType) {
	struct ReturnTypeAST* nn = malloc(sizeof(struct ReturnTypeAST));
	nn->type = ReturnType;
	nn->returnType = retType;

	return(struct AST*)nn;

}

struct AST* newDeclParam(struct Param* parameters, int numParam, struct Param param) {
	struct DeclParamsAST* nn = malloc(sizeof(struct DeclParamsAST));

	nn->type = DeclParam;
	if (parameters == NULL) {
		parameters = (struct Param*)malloc(sizeof(struct Param));
		parameters[0] = param;
		numParam = 1;
	}
	else {
		parameters = (struct Param*)realloc(parameters, (numParam + 1) * sizeof(struct Param));
		parameters[numParam] = param;
		numParam++;
	}
	nn->parameters = parameters;
	nn->numParams = numParam;

	return (struct AST*)nn;
}

struct AST* newNodeReturn(int retType, struct AST* retVal) {
	struct NodeReturnAST* nn = malloc(sizeof(struct NodeReturnAST));
	nn->type = ReturnNode;
	nn->returnType = retType;
	nn->returnVal = retVal;

	return(struct AST*)nn;

}

struct AST* newWrite(struct list_t* entry) {
	struct WriteNodeAST* nn = malloc(sizeof(struct WriteNodeAST));
	nn->type = Writer;
	nn->entry = entry;
}

struct AST* newWriteLine() {
	struct WriteLineAST* nn = malloc(sizeof(struct WriteLineAST));
	nn->type = WriteLine;
}

struct AST* newRead(struct list_t* entry, union Value val) {
	struct ReadAST* nn = malloc(sizeof(struct ReadAST));
	nn->type = Reader;
	nn->entry = entry;
	nn->val = val;
}

void printAST(struct AST* node) {

	struct DeclsAST* tempDeclsAST;
	struct DeclAST* tempDeclAST;
	struct ConstAST* tempConstAST;
	struct StmtsAST* tempStmtsAST;
	struct IfAST* tempIfAST;
	struct WhileAST* tempWhileAST;
	struct AssignAST* tempAssignAST;
	struct SimpleAST* tempSimpleAST;
	struct FuncCallAST* tempFuncCallAST;
	struct CallParamsAST* tempCallParamsAST;
	struct ArithmAST* tempArithmAST;
	struct BoolAST* tempBoolAST;
	struct RelAST* tempRelAST;
	struct EquAST* tempEquAST;
	struct RefAST* tempRefAST;
	struct FuncDeclsAST* tempFuncDeclsAST;
	struct FuncDecAST* tempFuncDecAST;
	struct ReturnTypeAST* tempReturnTypeAST;
	struct DeclParamsAST* tempDeclParamsAST;
	struct NodeReturnAST* tempNodeReturnAST;
	struct WriteNodeAST* tempWriteNodeAST;
	struct WriteLineAST* tempWriteLineAST;
	struct ReadAST* tempReadAST;


	switch (node->type) {

	case BaseNode:
		printf("Base Node\n");
		break;

	case Decls:
		tempDeclsAST = (struct DeclsAST*)node;
		printf("Decls node -->> %d \n", tempDeclsAST->type);
		break;
	case Decl:
		tempDeclAST = (struct DeclAST*)node;
		printf("Decl node with dataType: %d for %d names\n", tempDeclAST->dataType, tempDeclAST->namesCount);
		if (tempDeclAST->dataType == 1) {
			printf("	Int for %d names\n", tempDeclAST->namesCount);
		}
		else if (tempDeclAST->dataType == 2) {
			printf("Float for %d names\n", tempDeclAST->namesCount);
		}
		else if (tempDeclAST->dataType == 3) {
			printf("Char for %d names\n", tempDeclAST->namesCount);
		}
	case Const:
		tempConstAST = (struct ConstAST*)node;
		printf("Constant node of type %d with value ", tempConstAST->dataType);
		switch (tempConstAST->dataType) {
		case TYPE_INT:
			printf("%d\n", tempConstAST->val.ival);
			break;
		case TYPE_FLOAT:
			printf("%.2f\n", tempConstAST->val.fval);
			break;
		case TYPE_CHAR:
			printf("%c\n", tempConstAST->val.cval);
			break;
		}
		break;
	case Stmts:
		tempStmtsAST = (struct StmtsAST*)node;
		printf("Stmts node with %d stmts\n", tempStmtsAST->stmtsCount);
		break;
	case Ifs:
		tempIfAST = (struct IfAST*)node;
		printf("If statment started\n");
		if (tempIfAST->elseSec == NULL) {
			printf("No else\n");
		}
		else {
			printf("Else Statment\n");
		}
		break;
	case Whiles:
		printf("While Statement started\n");
		break;
	case Assign:
		tempAssignAST = (struct AssignAST*)node;
		printf("Assign Node with entry %s\n", tempAssignAST->entry->SymtableName);
		if (tempAssignAST->assignVal->type == Const) {
			struct ConstAST* nn = (struct ConstAST*)tempAssignAST->assignVal;
			tempAssignAST->entry->val = nn->val;
		}
		break;
	case Simples:
		tempSimpleAST = (struct SimpleAST*)node;
		printf("Simple node from statment %d\n", tempSimpleAST->statmentType);
		break;

	case FuncCall:
		tempFuncCallAST = (struct FuncCallAST*)node;
		printf("Function called wiht node %d paramets\n", tempFuncCallAST->numParams);
		break;
	case ParamCall:
		tempCallParamsAST = (struct CallParamsAST*)node;
		printf("Function Parameter called %d parameters\n", tempCallParamsAST->numParams);
		break;
	case Arithm:
		tempArithmAST = (struct ArithmAST*)node;
		printf("Arithmetic operator ");
		switch (tempArithmAST->op) {
		case 0:
			printf("+\n");
			break;
		case 1:
			printf("-\n");
			break;
		case 2:
			printf("*\n");
			break;
		case 3:
			printf("/\n");
			break;
		}
		break;
	case Bools:
		tempBoolAST = (struct BoolAST*)node;
		printf("Bool operator ");
		switch (tempBoolAST->op) {
		case 0:
			printf("||\n");
			break;
		case 1:
			printf("&&\n");
			break;
		case 2:
			printf("!\n");
			break;
		}
		break;
	case Relat:
		tempRelAST = (struct RelAST*)node;
		printf("Realtion operator ");
		switch (tempRelAST->op) {
		case 0:
			printf(">\n");
			break;
		case 1:
			printf("<\n");
			break;
		case 2: 
			printf(">=\n");
			break;
		case 3:
			printf("<=\n");
			break;
		}
		break;
	case Equ:
		tempEquAST = (struct EquAST*)node;
		printf("Equal operator ");
		switch (tempEquAST->op) {
		case 0:
			printf("==\n");
			break;
		case 1:
			printf("!=\n");
			break;
		}
		break;
	case Ref:
		tempRefAST = (struct RefAST*)node;
		printf("Variable reference entry: %s\n", tempRefAST->entry->SymtableName);
		break;
	case FuncDecls:
		tempFuncDeclsAST = (struct FuncDeclsAST*)node;
		printf("Function decls %d \n", tempFuncDeclsAST->funcDeclCount);
		break;
	case FuncDecl:
		tempFuncDecAST = (struct FuncDecAST*)node;
		printf("Function Decl of %s with return type ", tempFuncDecAST->entry->SymtableName);
		if (tempFuncDecAST->returnType == 1) {
			printf("int and %d parameters\n", tempFuncDecAST->entry->numParams);
		}
		else if (tempFuncDecAST->returnType == 2) {
			printf("Float and %d parameters\n", tempFuncDecAST->entry->numParams);
		}
		else if (tempFuncDecAST->returnType == 3) {
			printf("char and %d parameters\n", tempFuncDecAST->entry->numParams);
		}
		else if (tempFuncDecAST->returnType == 6) {
			printf("Void and %d parameters\n", tempFuncDecAST->entry->numParams);
		}
		break;
	case ReturnType:
		tempReturnTypeAST = (struct ReturnTypeAST*)node;
		printf("return type %d which is ", tempReturnTypeAST->returnType);
		break;
	case DeclParam:
		tempDeclParamsAST = (struct DeclParamsAST*)node;
		printf("Function decls params of %d paramers\n", tempDeclParamsAST->numParams);
		break;
	case ReturnNode:
		tempNodeReturnAST = (struct NodeReturnAST*)node;
		printf("Return node of type: %d\n", tempNodeReturnAST->returnType);
		break;
	case Reader:
		tempReadAST = (struct ReadAST*)node;
		break;
	case Writer:
		tempWriteNodeAST = (struct WriteNodeAST*)node;
		printf("Write node to variable %s\n", tempWriteNodeAST->entry->SymtableName);
		break;
	case WriteLine:
		tempWriteLineAST = (struct WriteLineAST*)node;
		printf("Writing new line\n");
		break;

	default:
		fprintf(stderr, "Error in node selection!\n");
		break;

	}
}




void EnterAST(struct AST* node) {
	int i;

	if (node == NULL) {
		printf("Error with enter AST\n");
		return;
	}

	if (node->type == BaseNode) {
		EnterAST(node->left);
		EnterAST(node->right);
		printAST(node);
	}
	else if (node->type == Decls) {
		struct DeclsAST* tempDeclsAST = (struct DeclsAST*)node;
		printAST(node);
	}
	else if (node->type == Stmts) {
		struct StmtsAST* tempStmtsAST = (struct StmtsAST*)node;
		printAST(node);
		for (i = 0; i < tempStmtsAST->stmtsCount; i++) {
			EnterAST(tempStmtsAST->stmts[i]);
		}
	}
	else if (node->type == Ifs) {
		struct IfAST* tempIfsAST = (struct IfAST*)node;
		printAST(node);
		printf("Condition:\n");
		EnterAST(tempIfsAST->condition);
		printf("If section:\n");
		EnterAST(tempIfsAST->ifSec);
		if (tempIfsAST->elseSec != NULL) {
			printf("Else section\n");
			EnterAST(tempIfsAST->elseSec);
		}
	}
	else if (node->type == Whiles) {
		struct WhileAST* tempWhileAST = (struct WhileAST*)node;
		printAST(node);
		printf("Condition:\n");
		EnterAST(tempWhileAST->condition);
		printf("While sectoin:\n");
		EnterAST(tempWhileAST->whileSec);
	}
	else if (node->type == Assign) {
		struct AssignAST* tempAssignAST = (struct AssignAST*)node;
		printAST(node);
		printf("Assigning:\n");
		EnterAST(tempAssignAST->assignVal);
	}
	else if (node->type == FuncCall) {
		struct FuncCallAST* tempFuncCallAST = (struct FuncCallAST*)node;
		printAST(node);
		printf("Call parameters:\n");
		for (i = 0; i < tempFuncCallAST->numParams; i++) {
			EnterAST(tempFuncCallAST->params[i]);
		}
	}
	else if (node->type == FuncDecls) {
		struct FuncDeclsAST* tempFuncDeclsAST = (struct FuncDeclsAST*)node;
		printAST(node);
		for (i = 0; i < tempFuncDeclsAST->funcDeclCount; i++) {
			EnterAST(tempFuncDeclsAST->funcDecls[i]);
		}
	}
	else if (node->type == FuncDecl) {
		struct FuncDecAST* tempFuncDecAST = (struct FuncDecAST*)node;
		printAST(node);
		if (tempFuncDecAST->entry->numParams != 0) {
			printf("Paramters:\n");
			for (i = 0; i < tempFuncDecAST->entry->numParams; i++) {
				printf("Parameter %s of type ", tempFuncDecAST->entry->parameters[i].param_name);
				if (tempFuncDecAST->entry->parameters[i].par_type == 1) {
					printf("int\n");
				}
				else if (tempFuncDecAST->entry->parameters[i].par_type == 2) {
					printf("float\n");
				}
				else if (tempFuncDecAST->entry->parameters[i].par_type == 3) {
					printf("char\n");
				}
			}
		}
		if (tempFuncDecAST->decls != NULL) {
			printf("Function decls: \n");
			EnterAST(tempFuncDecAST->decls);
		}
		if (tempFuncDecAST->statements != NULL) {
			printf("Function statemetns: \n");
			EnterAST(tempFuncDecAST->statements);
		}
		if (tempFuncDecAST->returnNode != NULL) {
			printf("Return node: \n");
			EnterAST(tempFuncDecAST->returnNode);
		}
	}
	else if (node->type == DeclParam) {
		struct DeclParamsAST* tempDeclParamsAST = (struct DeclParamsAST*)node;
		printAST(node);
		printf("Call Parameters:\n");
		for (i = 0; i < tempDeclParamsAST->numParams; i++) {
			printf("Parameter %s of type %d\n", tempDeclParamsAST->parameters[i].param_name, tempDeclParamsAST->parameters[i].par_type);
		}
	}
	else if (node->type == ReturnNode) {
		struct NodeReturnAST* tempNodeReturnAST = (struct NodeReturnAST*)node;
		printAST(node);
		printf("Returning:\n");
		EnterAST(tempNodeReturnAST->returnVal);
	}
	else if (node->type == Reader) {
		struct ReadAST* tempReadAST = (struct ReadAST*)node;
		printAST(node);
		printf("Reading value to %s\n", tempReadAST->entry->SymtableName);
	}
	else if (node->type == Writer) {
	struct WriteNodeAST* tempWriteNodeAST = (struct WriteNodeAST*)node;
	printAST(node);
	printf("Writing value of %s\n", tempWriteNodeAST->entry->SymtableName);
	}
	else if (node->type == WriteLine) {
	struct WriteLineAST* tempWriteLineAST = (struct WriteLineAST*)node;
	printAST(node);
	}


	else {
		printAST(node);
	}

}

#endif // !1
