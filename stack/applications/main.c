#include <stdio.h>
#include <stdlib.h>
#include "applications.h"

int main()
{
    Stack S;
	StackEntry item;
	CreateStack(&S);
	IntfixToPostfix("3+4*5$6/7-8",&S);
}
	