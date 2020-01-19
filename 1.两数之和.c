/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i,j;
	int *returnNum = (int*)malloc(sizeof(int) * 2);
	memset(returnNum, 0 ,sizeof(int) * 2);
	*returnSize = 0;
	
	for(i=0; i<numsSize-1; ++i){
		for(j=i+1; j<numsSize; ++j){
			if(nums[i]+nums[j]==target){
				returnNum[0] = i;
				returnNum[1] = j;
				*returnSize = 2;
				break;
			}
		}
	}

	return returnNum;
}

// @lc code=end

