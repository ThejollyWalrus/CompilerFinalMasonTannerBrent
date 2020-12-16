//Max SIZE
#define SIZE 211

//Max Token Length
#define MAXTOKENLEN 40

//Defining Token types
//Determines Type for Symbol table
#define UNDEF 0
#define TYPE_INT 1
#define TYPE_REAL 2
#define TYPE_STRING 3
#define LOGIC_TYPE 4
#define TYPE_ARRAY 5
//#define POINTER_TYPE 6
#define FUNCTION_TYPE 5
#define VOID_TYPE 6

//#define FUNCTION_TYPE 7
#define TYPE_CHAR 8
#define TYPE_BOOL 9
#define TYPE_DOUBLE 10
#define TYPE_FLOAT 11


#define NONE 0		// to check types only - assignment, parameter
#define ARITHM_OP 1 // ADDOP, MULOP, DIVOP (+, -, *, /)
#define INCR_OP 2   // INCR (++, --)
#define BOOL_OP 3   // OROP, ANDOP (||, &&)
#define NOT_OP 4    // NOTOP (!)
#define REL_OP 5    // RELOP (>, <, >=, <=)
#define EQU_OP 6    // EQUOP (==, !=)


/* how parameter is passed */
#define BY_REFERENCE 0
#define BY_VALUE 1

// a linked list of references (lineno's) for each variable
struct LineNumList {
	int lineno;
	struct LineNumList* next;
};

union Value {
	int ival;
	double fval;
	char cval;
	char* sval;
};

 struct Param {
	// parameter type and name
	int par_type;
	char param_name[MAXTOKENLEN];

	// to store the value
	union Value val;
	int passing; // value or reference
};

// struct that represents a list node
 struct list_t {
	// Name, size of Name, Scope and occurrences (lines)
	char SymtableName[MAXTOKENLEN];
	int st_size;
	int Scope;
	struct LineNumList* Lines;
	union Value val;
	//int val;
	union Value* vals;

	// to store value and sometimes more information
	//int st_ival; double st_fval; char* st_sval;

	// type
	int SymTable_Type;

	// for arrays (info type), for pointers (pointing type)
	// and for functions (return type)
	int inf_type;
	struct Param* parameters;
	int numParams;
	// array stuff
	
	// pointer to next item in the list
	struct list_t* next;
};

// The Hash table
static struct list_t** HashTable;

// Function Declarations
void InitHashTable(); // initialize Hash table
unsigned int Hash(char* Key); // Hash function 
void Insert_v(char* Name, int len, int lineno); // insert entry
struct list_t* LookUp(char* Name); // search for entry
void HideScope(); // hide the current Scope
void incrScope(); // go to next Scope
void build_symtab(FILE* of); // dump file
void setType(int val);