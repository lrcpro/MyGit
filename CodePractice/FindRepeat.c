
/*题目：找出数组中任意一个重复的数字
 长度为n，所有数字都在0～n-1范围内。*/

#include <stdio.h>
#include <assert.h>

int FindRepet(int num[], int len)
{
    assert(num != NULL);
    assert(!(len <= 0));
    for(int i=0; i<len; i++)
    {
        if(num[i]<0 || num[i]>len-1)
            return -1;
    }
    for(int i=0; i<len; i++)
    {
        while (num[i]!=i)
        {
            if (num[num[i]]==num[i])
                return num[i];
            //swap
            int tmp = num[i];
            num[i] = num[tmp];
            num[tmp] = tmp;
        }
    }
    return -1;

}
int main()
{
    int num[5] = {1,2,1,0,4};
    printf("%d",FindRepet(num, 5));
    return 0;
}

