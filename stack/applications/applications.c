#include <stdio.h>
#include <stdlib.h>
#include "applications.h"
/*
void Validation(char c)
{
	while(c != '+' ||c != '-' ||c != '*' || c != '/' ||c != '^' || c != '.' ||c != '(' || c != ')') 
	
}
*/

int IsDigit (char c)
{
	 return (c>='0' && c<= '9');
}


int Precedent(char PrevOP, char NewOP)
{
	if(PrevOP=='$') return 1;
	else if(PrevOP == '*' || PrevOP == '/') return(NewOP!='$'); 
	else if(PrevOP == '+' || PrevOP == '-') return(NewOP!='$' && NewOP!='*' && NewOP!='/' ); 
}


void IntfixToPostfix(char intfix[], Stack* Postfix) // A + B * C $ D / E - F
                                                   //  345 + 789
{
	char op,c;
	Stack s ;
	CreateStack(&s);
	for(int i=0 ; (c=intfix[i])!='\0' ; ++i)
	{
		if(IsDigit(c))
		{
			while (IsDigit(c))
			{
			   Push(c, Postfix);
			   i++;
			   c=intfix[i];
			}
		}
		else{
			StackTop(&op , &s);
			while(!StackEmpty(&s) && Precedent(op, c)) // if the comming io is less than the top Precedent returns 1
			{
				Pop (&op,&s);
				Push(op,Postfix);
				if(!StackEmpty(&s)) StackTop(&op , &s);
			}
			Push(c,&s);	
		}
	}
	while(!StackEmpty(&s)) 
	{
		Pop (&op,&s);
		Push(op,Postfix);
	}
	
	
}

