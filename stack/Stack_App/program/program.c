#include "program.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../stack/stack.h"


// Take string from user


char* SetString()
{
    char *str = (char *)calloc(1,sizeof(char));
    int len = 1;
    *str = '\0';
    char ch;
    ch = getchar();
    int cnt = 1;
    while(ch != '\n'){
        if(cnt == len)
        {
            str = (char *)realloc(str, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(str + cnt - 1) = ch;
        *(str + cnt) = '\0';
        cnt++;
        ch = getchar();
    }
    fflush(stdin);
    if(len == 1 ) return SetString();
    return str;
}


// convert String to int


int StringToInt(char* StringNum)
{
    int num = 0;
    for(int i = 0; i < strlen(StringNum); i++)
    {
        if(!isdigit(StringNum[i])) return -1;
        num *= 10;
        num += StringNum[i] - '0';
    }
    return num;
}

int ChoiceValidation(){
    char *temp;
    int var;
    do{
        temp = SetString();
        var = StringToInt(temp);
    }while(var != 1 && var != 2 && printf("\nInvalid Choice, try again...\n\nYour Choice : "));
    return var;
}

//

int Precedent(char PrevOP, char NewOP)
{
	if(PrevOP == '^') return 1;
	else if(PrevOP == '*' || PrevOP == '/') return(NewOP != '^');
	else if(PrevOP == '+' || PrevOP == '-') return(NewOP != '^' && NewOP != '*' && NewOP != '/' );
}

//


int is_digit(char ch){
	
	return (ch >= '0' && ch <='9');
}

int is_operator(char ch)
{
    return (ch == '-' || ch == '+' || ch =='*' || ch =='/' || ch =='^' || ch =='(' || ch ==')');
}


// validate choice	


int ChoiceValidate()
{
    int choice;
    char *temp;
    do{
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice!=1 && choice!=2) && printf("\nInvalid Choice! please try again..\n\nYour Choice : "));
    return choice;
}

int Validate_Parentheses(char *str)
{
    Pstack s;
    CreateStack(&s);
    char e;
    for (int i = 0; i < strlen(str); ++i) { // 5 + () 6
        if(str[i] == '(') Push_Stack((void*)&str[i], s, sizeof(str[i]));
        if(str[i] == ')')
        {
            if(!StackEmpty(s))
            Pop_Stack((void*)&e, s, sizeof(e));
            else return false;
        }
    }
    return (!(StackSize(s))) ;
}

int Validate_brackets(char c1, char c2)
{
    if(c1 == '(' && c2 == ')')
    {
        return 0;
    }
    else if( ((c1 == ')' && is_digit((c2)))) || ((c2 == '(' && is_digit((c1)))) )
    {
        return 0;
    }
    else return 1;
}


int check_invalid_symbol(char c)
{
    if (!is_digit(c) && c != '-' && c != '+' && c != '*' && c != '/' && c != '^' && c != '.' && c != '(' && c != ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int check_squence(char c1, char c2)
{
    if (c1 == '-' || c1 == '+' || c1 == '*' || c1 == '/' || c1 == '^' || c1 == '(')
    {
        if (c2 == '*' || c2 == '/' || c2 == '^' || c2 == ')')
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
}


char *Validate_expression()
{
    bool flag = 0;
    char *str;
    do {
        str = SetString();
        flag = 0;
        for (int i = 0; i < strlen(str); ++i)
        {
            if(str[i] == ' ') continue;
            flag = Validate_brackets(str[i], str[i+1]);
            if(!flag) break;
            flag = check_invalid_symbol(str[i]);
            if(!flag) break;
            flag = check_squence(str[i], str[i+1]);
            if(!flag) break;
        }
        if (str[0] == '*' || str[0] == '/' || str[0] == '^' || str[0] == ')' || (!is_digit(str[strlen(str) - 1]) && str[strlen(str) - 1] != ')'))
        {
            flag = 0;
        }
    }while((!flag || !Validate_Parentheses(str)) && printf("\n\nInvalid expression, Try Again...\n\nyour expression : "));
    return str;
}

void InfixToPostfix(const char* infix, Pstack Postfix)
{
    char op, c;
    int temp = 0, negative;
    Pstack operations ;
    CreateStack(&operations);
    for(int i = 0; (c = infix[i]) != '\0'; ++i)
    {
        temp = 0;
        if( (infix[i+1] == '-' && is_operator(c)) || (i == 0 && c == '-'))
        {
            negative = 1;
        }
        else
        {
            negative = 0;
        }
        if(is_digit(c))
        {
            while (is_digit(c))
            {
                temp *= 10;
                temp += c - '0';
                ++i;
                c = infix[i];
            }
            if(negative || (!StackSize(Postfix) && infix[0] == '-')) temp *= -1;
            Push_Stack((void *)&temp, Postfix, sizeof(temp));
        }
        if((i == 0 && c == '-')) continue;
        if(!StackEmpty(operations)) {
            StackTop((void *) &op, operations, sizeof(op));
        }
        while(!StackEmpty(operations) && Precedent(op, c) )
            {
                Pop_Stack((void*)&op, operations, sizeof(op));
                int x = (int)op;
                Push_Stack((void*)&x, Postfix, sizeof(x));
                if(!StackEmpty(operations))
                {
                    StackTop((void*)&op, operations, sizeof(op));
                }
            }
        if(c !='\0')
        {
            Push_Stack((void*)&c, operations, sizeof(c));
        }
        printf("\n");
        if(negative && !(i == 0 && c == '-'))
        {
            ++i;
        }
    }
    while(!StackEmpty(operations))
    {
        Pop_Stack((void*)&op, operations, sizeof(op));
        int x = (int)op;
        Push_Stack((void*)&x, Postfix, sizeof(x));
    }
}

Pstack ReverseStack(Pstack s)
{
    Pstack temp;
    CreateStack(&temp);
    int x = 0;
    while(!StackEmpty(s))
    {
        Pop_Stack((void*)&x, s, sizeof(x));
        if(is_operator((char)x))
        {
            char y = (char)x;
            Push_Stack((void*)&y, temp, sizeof(y));
        }
        else
        {
            Push_Stack((void*)&x, temp, sizeof(x));
        }
    }
    return temp;

}

double CalcVal(double op1, double op2, char op)
{
    if(op == '+') return (op1 + op2);
    else if(op == '-') return (op1 - op2);
    else if(op == '*') return (op1 * op2);
    else if(op == '/')
    {
        if(op2) return op1 / op2;
        else
        {
            printf("\nInvalid division !\n");
            return 0.0;
        }
    }
    else  return  (pow(op1,op2));
}



double EvaluatePostfix(Pstack Postfix)
{
    Pstack temp;
    int num, op;
    double val, op1, op2;
    CreateStack(&temp);
    while (!StackEmpty(Postfix))
    {
        StackTop((void*)&num, Postfix, sizeof(num));
        if(is_operator((char)num))
        {

            Pop_Stack((void*)&op, Postfix, sizeof(op));
            Pop_Stack((void*)&op2, temp, sizeof(op2));
            Pop_Stack((void*)&op1, temp, sizeof(op1));
            char xx = (char)op;
            val = CalcVal(op1, op2, xx);
            if(StackEmpty(Postfix)) return val;
            Push_Stack((void*)&val, temp, sizeof(val));
        }
        else
        {
            double var = (double)num;
            Push_Stack((void*)&var, temp, sizeof(var));
            Pop_Stack((void*)&num, Postfix, sizeof(num));
        }
    }
    Pop_Stack((void*)&val, temp, sizeof(val));
    return val;
}