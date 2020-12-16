// Mason Hamilton
// Tanner Williams 
// Brent Lund
// CST-405
// Professor Nasser Tadayon

#include "theMips.h"

void startMips(struct AST* nn)
{
	if (nn == NULL) {
		printf("No mips entry generated\n");
		return;
	}
	else {
		
		switch (nn->type) 
		{
			case Decls:
				if (nn->left->type == Decl) {
					exprMips(nn);
				}
				break;
			case Decl:
				if (nn->type == Decls) {
					printMips(nn);
				}
				break;
			default:
				printf("Unassiged mips register\n");
				exit(1);

		}


	}
}

void exprMips(struct DeclsAST* nn) {
	if (nn == NULl) {
		printf("No mips entry generated\n");
		return;
	}
	else {
		switch (nn->declsCount > 0)
		{
			for (int i = 0; i < nn->declsCount; i++) {
				printMips();
			}
		}
	}
}

void equalEquMips(struct EquAST* nn) {

	if (nn == NULL) {
		printf("No mips entry generated\n");
		return;
	}
	else {
		switch (nn->op) {
		case AddOp:
			if (nn->left->type == TYPE_INT) {
				int x, y, z;
				x = nn->left;
				y = nn->right;
				z = x + y;

			}
			else if (nn->right->type == TYPE_INT;) {
				int x, y, z;
				y = nn->left;
				x = nn->right;
				z = x + y;
			}
			break;
		case SubOp:
			if (nn->left->type == TYPE_INT) {
				int x, y, z;
				x = nn->left;
				y = nn->right;
				z = x - y;
			}
			else if (nn->right->type == TYPE_INT;) {
				int x, y, z;
				y = nn->left;
				x = nn->right;
				z = x - y;
			}
			break;

		default:
			printf("Unassiged mips register\n");
			exit(1);
		}
	}

}


void printMips(const char* label, struct list_t* symTab) {

	if (symTab == NULL) {
		printf("No mips entry generated\n");
		return 0;
	}

	else {
		switch (symTab->parameters) {
			case 
		}
	}

}

