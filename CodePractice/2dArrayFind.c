/*
 题目：一个二维数组中，每行按照左到右递增，每列按照上到下递增，完成一个函数可以找到数组
 的一个数。有返回true，无返回false。
 */
#include <stdio.h>
#include <stdbool.h>

bool Find(int arr[4][4], int Row, int Col, int num)
{
    if (arr==NULL || Row<0 || Col< 0)
    {
        return false;
    }
    int row = 0;
    int col = Col-1;
    while (row<Row && col>=0)
    {
        if (arr[row][col] == num)
        {
            return true;
        }
        if (num<arr[row][col])
        {
            col--;
        }
        else
            arr++;
    }
    return false;
}

int main()
{
    int arr[4][4] =
    {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}
    };
    bool ret = Find(arr, 4, 4, 5);
    printf("%d\n",ret);
    return 0;
}
