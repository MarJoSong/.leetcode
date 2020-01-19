/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i,len;
    int upflag=1;
    int *retnum = (int*)malloc(sizeof(int) * (digitsSize+1));
    memset(retnum, 0 , sizeof(int) * (digitsSize+1));
    memcpy(retnum+1, digits, sizeof(int) * (digitsSize));

    for(i=digitsSize; i>0; --i){
        retnum[i] = (digits[i-1]+upflag)%10;
        upflag = (digits[i-1]+upflag)/10;
        printf("%d\n", retnum[i]);
    }
    if(upflag){
        retnum[0]=1;
        digitsSize++;
    }else{
        retnum++;
    }
    *returnSize = digitsSize;
    return retnum;
}

// @lc code=end

