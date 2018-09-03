#ifndef CalcRPN_h
#define CalcRPN_h

#include <stdio.h>

//Stack-------------------------------------------------------Stack
#define MAX_SIZE 30
typedef int DataType;

typedef struct stack
{
    DataType _arr[MAX_SIZE];
    int _top ;
}Stack;

void StackInit(Stack *s);
void StackPush(Stack* s, DataType d);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);
//--------------------------------------------------------------

int CalcRPN(const char* ptr);


#endif /* CalcRPN_h */

