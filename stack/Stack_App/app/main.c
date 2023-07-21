#include <stdio.h>
#include <string.h>
#include "../program/program.h"

void Display(void *e)
{
    int y;
    memcpy(&y, e, sizeof(y));
    if(is_operator((char)y)) printf("%c", (char)y);
    else printf("%d", y);
}

int main()
{
    printf("\n\t\t\t<--------------------------Welcome !-------------------------->\n\n");
    Pstack st, st2;
    CreateStack(&st);
    CreateStack(&st2);
    int choice;
    char *operation;
    double val;
	while(1)
    {
        printf("\n\n1- Convert from infix to postfix  \t\t 2- Quit\n\nyour Choice : ");
        choice = ChoiceValidation();
        if(choice == 1)
        {
            printf("\nEnter your expression : ");
            operation = Validate_expression();
            InfixToPostfix(operation,st);
            printf("Your expression in Postfix : ");
            st2 = ReverseStack(st);
            TraverseStack(st2, &Display);
            val = EvaluatePostfix(st2);
            printf("\n\nThe result = %lf", val);
        }
        else break;
	}
    return 0;
}

