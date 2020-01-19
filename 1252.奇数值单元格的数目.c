/*
 * @lc app=leetcode.cn id=1252 lang=c
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start


int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int i, j, k, count = 0;
    const int x=n;
    const int y=m;
    int **tmp = (int **)malloc(sizeof(int*) * n);
    for(i=0; i<n; ++i){
        tmp[i] = (int *)malloc(sizeof(int) * m);
    }
    
    for(i=0; i< indicesSize; ++i){
        for(k=0; k<m; ++k){
            tmp[indices[i][0]][k]++;
        }
        for(j=0; j<n; ++j){
            tmp[j][indices[i][1]]++;
        }
    }
    
    for(j=0;j<n;++j){
        for(k=0;k<m;++k){
            if(tmp[j][k]%2) count++;
        }
    }
    return count;
}


// @lc code=end

