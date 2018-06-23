/*题目：
 在一个长度为n+1的数组里所有数字在1～n范围内，所以至少有一个是重复的，找出任意一个重复数字不修改数组。
 分析及解决方案：
 借鉴二分查找的思路解决，将数组分为1～m和m+1～n两部分，如果1～m范围内有超过m个数则在这个范围内，否则在后半部分内。然后继续分成两部分查找。
*/

#include <stdio.h>
#include <assert.h>

int BinaryFindRepeat(int arr[], int len)
{
    assert(arr != NULL);
    for (int i = 0; i<len ; i++)
    {
        if(arr[i]>len || arr[i]<1)
            return -1;
    }
    int start = 1;
    int end = len - 1;
    while (end>=start)
    {
        int mid = ((end-start)>>1)+start;
        int count = 0;
        for (int i = 0; i<len; i++)
        {
            if (arr[i]>=start && arr[i]<=mid)
            {
                count ++;
            }
        }
        if(count>mid-start+1)
        {
            end  = mid;
        }
        else
        {
            start = mid+1;
        }
        if (end == start)
        {
            return arr[start];
        }
    }
    return -1;
}

int main()
{
    int arr[8] = {1,2,2,4,5,6,7,3};
    int num = BinaryFindRepeat(arr, 8);
    if (num>0)
    {
        printf("%d\n",num);
    }
    
    return 0;
}

