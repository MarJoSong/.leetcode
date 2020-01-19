/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int x=0, y=numbersSize-1;
    int *arr = (int *)malloc(sizeof(int) * 2);
    for( ; x!=y; ){
        if(target > numbers[x] + numbers[y]){
            x++;
        }else if(target < numbers[x] + numbers[y]){
            y--;
        }else{
            break;
        }
    }
    if(x!=y){
        arr[0]=x+1;
        arr[1]=y+1;
        *returnSize=2;
        return arr;
    }
    return NULL;
}


// @lc code=end

