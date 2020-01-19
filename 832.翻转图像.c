/*
 * @lc app=leetcode.cn id=832 lang=c
 *
 * [832] 翻转图像
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int i, j;
    int **tmp = (int **)malloc(sizeof(int*) * ASize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * ASize);
    memset(tmp, 0, sizeof(int*) * ASize);
    for(i=0; i<ASize; ++i){
        printf("---- i:%d ----\n", i);
        tmp[i] = (int *)malloc(sizeof(int) * AColSize[i]);
        memset(tmp, 0, sizeof(int) * AColSize[i]);
        (*returnColumnSizes)[i] = AColSize[i];

        for(j=0; j<AColSize[i]/2; ++j){
            printf("---- i:%d, j:%d, AColSize[i]:%d, A[i][AColSize[i]-1-j]:%d, tmp[i][j]:%d ----\n", i, j, AColSize[i], A[i][AColSize[i]-1-j], tmp[i][j]);
            tmp[i][j] = (A[i][AColSize[i]-1-j]==0?1:0);
            printf("---- i:%d, j:%d, AColSize[i]:%d, A[i][AColSize[i]-1-j]:%d, tmp[i][j]:%d ----\n", i, j, AColSize[i], A[i][AColSize[i]-1-j], tmp[i][j]);
            tmp[i][AColSize[i]-1-j] = (A[i][j]==0?1:0);
        }
        tmp[i][j] = (A[i][j]==0?1:0);
    }
    *returnSize = ASize;
    return tmp;
}

// @lc code=end

