#include "CalcRPN.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

//Stack---------------------------------------------------
void StackInit(Stack *s)
{
    assert(s);
    s->_top = 0;
    for (int i = 0; i<MAX_SIZE; i++)
    {
        s->_arr[i]=0;
    }
}

void StackPush(Stack* s, DataType d)
{
    assert(s);
    if(s->_top == MAX_SIZE)
    {
        printf("full stack\n");
        return ;
    }
    else
    {
        s->_arr[s->_top] = d;
        s->_top ++;
    }
}
int StackEmpty(Stack* s)
{
    if (s->_top==0)
    {
        return 1;
    }
    return 0;
}

void StackPop(Stack* s)
{
    assert(s);
    if (StackEmpty(s))
    {
        printf("empty stack\n");
        return ;
    }
    
    s->_top --;
}

DataType StackTop(Stack* s)
{
    assert(s);
    return s->_arr[s->_top -1];
}

int StackSize(Stack* s)
{
    return s->_top;
}

//-------------------------------------------------------------------

int CalcRPN(const char* ptr)
{
    assert(ptr);
    Stack s;
    StackInit(&s);
    
    int len = (int)strlen(ptr);
    int flag = 0;int num = 0;
    for (int i = 0; i<len; i++)
    {
        
        if (ptr[i]>'0' && ptr[i]<'9')
        {
            num = num*10 + ptr[i]-'0';
            flag = 1;
        }
        else if (flag && ptr[i] == ' ')
        {
            StackPush(&s, num);
            flag = 0; num = 0;
        }
        else if (!flag && ptr[i]==' ')
            ;
        else
        {
            int right = StackTop(&s); StackPop(&s);
            int left = StackTop(&s); StackPop(&s);
            switch (ptr[i])
            {
                case '+':
                    StackPush(&s, left+right);
                    break;
                case '-':
                    StackPush(&s, left-right);
                    break;
                case '*':
                    StackPush(&s, left*right);
                    break;
                case '/':
                    StackPush(&s, left/right);
                    break;
                default:
                    break;
            }
        }
    }
    
    return StackTop(&s);
}
