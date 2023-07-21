#ifndef PORGRAM_H
#define PROGRAM_H

#include "../stack/stack.h"


char* SetString();

int StringToInt(char*);

int ChoiceValidate();

int ChoiceValidation();

int is_operator(char ch);

void InfixToPostfix(const char* infix, Pstack Postfix);

int Validate_brackets(char c1, char c2);

int check_invalid_symbol(char c);

char *Validate_expression() ;

int Validate_Parentheses(char *str);

int check_squence(char c1, char c2);

int is_digit(char ch);

double EvaluatePostfix(Pstack Postfix);

Pstack ReverseStack(Pstack s);

double CalcVal(double op1, double op2, char op);

void Display1(void *e);



#endif