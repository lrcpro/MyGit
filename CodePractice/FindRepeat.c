
/*题目：找出数组中任意一个重复的数字
 长度为n，所有数字都在0～n-1范围内。*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool FindRepet(int arr[], int len, int* num)
{
    assert(arr != NULL);
    if(len <= 0)
    {
        return false;
    }
    for(int i=0; i<len; i++)
    {
        if(arr[i]<0 || arr[i]>len-1)
            return false;
    }
    for(int i=0; i<len; i++)
    {
        while (arr[i]!=i)
        {
            if (arr[arr[i]]==arr[i])
            {
                *num = arr[i];
                return true;
            }
            //swap
            int tmp = arr[i];
            arr[i] = arr[tmp];
            arr[tmp] = tmp;
        }
    }
    return false;
    
}
int main()
{
    int arr[5] = {1,2,1,0,4};
    int num = 0;
    if (FindRepet(arr, sizeof(arr)/sizeof(arr[0]), &num))
    {
        printf("%d\n",num);
    }
    else
        printf("Can't find or error input!\n");
    return 0;
}
