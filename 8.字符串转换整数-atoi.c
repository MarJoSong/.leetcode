/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start


#define INT_MAX 2147483647

#define INT_MIN (-INT_MAX - 1)


int myAtoi(char * str){
        char *p = NULL;
        char *pp = NULL;
        char *fpp = NULL;
        char *ffpp = NULL;
        char *fp = NULL;
        int flag = 1;
        int len = 0;
        long num = 0;
        int isfind = 0;
        //int max = INT_MAX;
        //int min = INT_MIN;
        int max = 2147483647;
        int min = (-2147483647-1);
        len = strlen(str);
        printf("%s, %d\n", str, len);
        p = (char*)malloc(sizeof(char) * (len+1));
        pp = (char*)malloc(sizeof(char) * (len+1));
        if(NULL != pp || NULL != p) {
                memset(pp,'\0',sizeof(char) * (len+1));
                memset(p,'\0',sizeof(char) * (len+1));
        }
        fpp = pp;
        ffpp = pp;
        fp = p;
        strcpy(p,str);
        while(*p == ' ') {
                p++;
        }
        if(*p == '-'){
                p++;
                *pp = '-';
                fpp++;
                pp++;
                flag = 0;
        }
        while(isdigit(*p) && len) {
                *pp++ = *p++;
                len--;
                isfind = 1;
        }
        if(!isfind) {
                return 0;
        } 
        num = atoi(fpp) * (flag ? 1:-1);
        printf("%s, %d\n", fpp, num);
        free(fp);
        fp = NULL;
        free(ffpp);
        ffpp = NULL;
        if(num >= max)
        {
                num = max;
        } else if( num <= min)
        {
                num = min;
        }
        return num;
}


// @lc code=end

