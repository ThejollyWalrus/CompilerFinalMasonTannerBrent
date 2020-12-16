#ifndef THETREE_H
#define THETREE_H


enum NodeType {
	BaseNode,
	Decls,
	Decl,
	Const,
	Stmts,
	Ifs,
	Whiles,
	Assign,
	Simples,
	FuncCall,
	ParamCall,
	Arithm,
	Bools,
	Relat,
	Equ,
	FuncDecls,
	FuncDecl,
	ReturnType,
	DeclParam,
	ReturnNode,
	Ref,
	Reader,
	Writer,
	WriteLine

};

enum opArithm {
	AddOp,
	SubOp,
	MulOp,
	DivOp
};

enum opBool {
	CondOr,
	CondAnd,
	CondNot
};

enum opRel {
	CondGreater,
	CondLess,
	CondGreaterEqual,
	CondLessEqual
};

enum opEqu {
	CondEqual,
	CondNotEqual
};

struct AST {
	enum NodeType type;
	struct AST* left;
	struct AST* right;
};

struct DeclsAST {
	enum NodeType type;
	struct AST** decls;
	int declsCount;
};

struct DeclAST {
	enum NodeType type;
	int dataType;
	struct list_t** names;
	int namesCount;
};

 struct ConstAST {
	enum NodeType type;
	int dataType;
	union Value val;
	//int val;
};

struct StmtsAST {
	enum NodeType type;
	struct AST** stmts;
	int stmtsCount;
};

struct IfAST {
	enum NodeType type;

	struct AST* condition;
	struct AST* ifSec;
	struct AST* elseSec;
};

struct WhileAST {
	enum NodeType type;

	struct AST* condition;
	struct AST* whileSec;
};


struct AssignAST {
	enum NodeType type;
	struct list_t* entry;
	struct AST* assignVal;

};

struct SimpleAST {
	enum NodeType type;
		
	int statmentType;
};

struct FuncCallAST {
	enum NodeType type;
	struct list_t* entry;
	struct AST** params;
	int numParams;
};

struct CallParamsAST {
	enum NodeType type;
	struct AST** params;
	int numParams;
};

struct ArithmAST {
	enum NodeType type;

	enum opArithm op;
	struct AST* left;
	struct AST* right;
};

struct BoolAST {
	enum NodeType type;
	enum opBool op;
	struct AST* left;
	struct AST* right;
};

struct RelAST {
	enum NodeType type;
	enum opRel op;
	struct AST* left;
	struct AST* right;
};

struct EquAST {
	enum NodeType type;
	enum opEqu op;
	struct AST* left;
	struct AST* right;
};

struct RefAST {
	enum NodeType type;
	struct list_t* entry;

};

struct FuncDeclsAST {
	enum NodeType type;
	struct AST** funcDecls;
	int funcDeclCount;
};

struct FuncDecAST {
	enum NodeType type;
	int returnType;
	struct list_t* entry;
	struct AST* decls;
	struct AST* statements;
	struct AST* returnNode;

};

struct ReturnTypeAST {
	enum NodeType type;
	int returnType;

};

struct DeclParamsAST {
	enum NodeType type;
	struct Param* parameters;
	int numParams;
};

struct NodeReturnAST {
	enum NodeType type;
	int returnType;
	struct AST* returnVal;
};

struct WriteNodeAST {
	enum NodeType type;
	struct list_t* entry;
};

struct WriteLineAST {
	enum NodeType type;

};

struct ReadAST {
	enum NodeType type;
	struct list_t* entry;
	union Value val;
};



struct AST* newNode(enum NodeType Type,struct AST* left,struct  AST* right);
struct AST* newDecls(struct AST** decls, int declsCount, struct AST* declaration);
struct AST* newDecl(int dataType, struct list_t** names, int namesCount);
struct AST* newConst(int dataType, union Value val);
struct AST* newStmts(struct AST** stmts, int stmtsCount,struct AST* stmt);
struct AST* newIf(struct AST* condition, struct AST* ifSec, struct AST* elseSec);
struct AST* newWhile(struct AST* condition, struct AST* whileSec);
struct AST* newAssign(struct list_t* entry, struct AST* assignVal);
struct AST* newSimple(int statmentType);
struct AST* newFuncCall(struct list_t* entry, struct AST** params, int NumParams);
struct AST* newParamsCall(struct AST** params, int numParam, struct AST* param);
struct AST* newArithm(enum opArithm op, struct AST* left, struct AST* right);
struct AST* newBool(enum opBool op, struct AST* left, struct AST* right);
struct AST* newRel(enum opRel op, struct AST* left, struct AST* right);
struct AST* newEqu(enum opEqu op, struct AST* left, struct AST* right);
struct AST* newRef(struct list_t* entry);
struct AST* newFuncDecls(struct AST** funcDecls, int funcDeclsCount, struct AST* funcDecl);
struct AST* newFunDec(int retType, struct list_t* entry);
struct AST* newReturnType(int retType);
struct AST* newDeclParam(struct Param* parameters, int numParam, struct Param param);
struct AST* newNodeReturn(int retType, struct AST* retVal);
struct AST* newWrite(struct list_t* entry);
struct AST* newWriteLine();
struct AST* newRead(struct list_t* entry, union Value val);

void printAST(struct AST* node);
void EnterAST(struct AST* node);


#endif // !1
