/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start

int reverse(int x){
    int flag = 0;
    char p[12]={0};
    char *strNum = NULL;
    char maxPositive[12] = "2147483647";
    char minNagetive[12] = "2147483648";
    sprintf(p, "%d", x);
    printf("strNum = %s\n", p);
    strNum = p;
    if('-'==strNum[0]){
        strNum++;
        flag=1;
    }
    for(int i=0; i<strlen(strNum)/2; ++i){
        char tmp = strNum[i];
        strNum[i]=strNum[strlen(strNum)-i-1];
        strNum[strlen(strNum)-i-1] = tmp;
    }
    printf("%d\n", flag);
    printf("%s\n", strNum);
    if(flag && strlen(strNum)>9 && strncmp(strNum, minNagetive, 10)>=0){
        return 0;
    }
    if(!flag && strlen(strNum)>9 && strncmp(strNum, maxPositive, 10)>=0){
        return 0;
    }

    printf("M= %s\n", maxPositive);
    return atoi(strNum) * (flag?-1:1);
}

// @lc code=end

