/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start

int lengthOfLastWord(char * s){
    char *flag;
    int len = strlen(s);
    char *tmp = (char*)malloc(len+1);
    memset(tmp, 0 , len+1);
    memcpy(tmp, s, len+1);
    while(flag=strrchr(tmp,' ')){
        if(len=strlen(flag+1)){
            break;
        }else{
            *flag = '\0';
            len = strlen(tmp);
        }
    }
    free(tmp);
    tmp = NULL;
    return len;
}


// @lc code=end

