/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char **tmp, int left, int right, char* str, int *returnSize){
    if(0==left && 0==right){
        memcpy(tmp[*returnSize], str, strlen(str));
        (*returnSize)++;
        return;
    }
    char *strcp = (char *)malloc(strlen(str)+2);
    memset(strcp, 0 , strlen(str)+2);
    memcpy(strcp, str, strlen(str));
    if(0 < left){
        strcat(tmp[*returnSize],"(");
        memset(strcp, 0 , strlen(str)+2);
        memcpy(strcp, str, strlen(str));
        strcat(strcp,"(");
        dfs(tmp, left-1, right, strcp, returnSize);
    }
    if(left < right){
        strcat(tmp[*returnSize],")");
        memset(strcp, 0 , strlen(str)+2);
        memcpy(strcp, str, strlen(str));
        strcat(strcp,")");
        dfs(tmp, left, right-1, strcp, returnSize);
    }
    free(strcp);
    strcp = NULL;
}
char ** generateParenthesis(int n, int* returnSize){
    int i=0;
    char **tmp = NULL;

    if(n<=0) return tmp;

    tmp = (char **)malloc(sizeof(char*) *( 1<<2*(n-1) ));
    memset(tmp, 0, sizeof(char*) *( 1<<2*(n-1) ));
    *returnSize = 0;
    for( ; i<1<<2*(n-1); ++i){
        tmp[i] = (char *)malloc(sizeof(char) * (2*n+1));
        memset(tmp[i], 0, sizeof(char) * (2*n+1));
    }
    dfs(tmp, n, n, "", returnSize);
    return tmp;
}

// @lc code=end

