/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void quickSort(int *arr, int left, int right){
    if(left==right) return;
    int i = left;
    int j = right;
    int tmp, t;
    tmp = arr[i];
    while(i!=j){
        while(i<j && arr[j]>=tmp){
            --j;
        }

        while(i<j && arr[i]<=tmp){
            ++i;
        }
        if(i<j){
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[left] = arr[i];
    arr[i] = tmp;
    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0;
    int *arr = (int *)malloc(sizeof(int) * 2);
    int x=-1, y=-1;
    int *posHead=NULL, *posTail=NULL;
    int *tmp = (int *)malloc(sizeof(int) * numsSize);
    memset(tmp, 0 , sizeof(int) * numsSize);
    for( ; i<numsSize; ++i){
        tmp[i] = nums[i];
    }
    quickSort(tmp, 0, numsSize-1);
    posHead=&tmp[0];
    posTail = &tmp[numsSize-1];
    for( ; posHead!=posTail; ){
        if(target > *posHead + *posTail){
            posHead++;
        }else if(target < *posHead + *posTail){
            posTail++;
        }else{
            break;
        }
    }

    for(i=0; i<numsSize; ++i){
        if(nums[i]==*posHead){
            x=i;
        }
        if(nums[i]==*posTail){
            y=i;
        }
    }
    
    arr[0] = x>y?y:x;
    arr[1] = x<y?y:x;
    if(arr[0]!=-1 && arr[1]!=-1){
        return arr;
    }else{
        return NULL;
    }
}


// @lc code=end

