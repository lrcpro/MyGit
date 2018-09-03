#include <stdio.h>
#include "CalcRPN.h"

int main()
{
    char* ptr = "12 3 4 + * 6 - 8 2 / +";
    
    int i = CalcRPN(ptr);
    
    printf("%d\n",i);
    return 0;
}
