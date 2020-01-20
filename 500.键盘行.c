/*
 * @lc app=leetcode.cn id=500 lang=c
 *
 * [500] 键盘行
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize){
    char **returnwords = (char **)malloc(sizeof(char *) * wordsSize);
    *returnSize = 0;
    memset(returnwords, 0, sizeof(char *) * wordsSize);
    for(int i=0, j=0; i<wordsSize; ++i, j=0)
    {
        unsigned int sum = 0;
        while ( *(words[i]+j) )
        {
            switch( *(words[i]+j) )
            {
                //第一行
                case 'Q':
                case 'q':
                case 'W':
                case 'w':
                case 'E':
                case 'e':
                case 'R':
                case 'r':
                case 'T':
                case 't':
                case 'Y':
                case 'y':
                case 'U':
                case 'u':
                case 'I':
                case 'i':
                case 'O':
                case 'o':
                case 'P':
                case 'p':
                    sum += 1;
                    break;
                case 'A':
                case 'a':
                case 'S':
                case 's':
                case 'D':
                case 'd':
                case 'F':
                case 'f':
                case 'G':
                case 'g':
                case 'H':
                case 'h':
                case 'J':
                case 'j':
                case 'K':
                case 'k':
                case 'L':
                case 'l':
                    sum += 100;
                    break;
                case 'Z':
                case 'z':
                case 'X':
                case 'x':
                case 'C':
                case 'c':
                case 'V':
                case 'v':
                case 'B':
                case 'b':
                case 'N':
                case 'n':
                case 'M':
                case 'm':
                    sum += 10000;
                    break;
                default:
                    break;
            }
        }
        if(sum/10000)
        {
            if(sum%10000)
            {
                continue;
            }
            //扩列
            returnwords[*returnSize] = (char *)malloc(sizeof(words[i]));
            memset(returnwords[*returnSize], 0, sizeof(words[i]));
            *returnSize++;
        }
        else if(sum/100)
        {
            if(sum%100)
            {
                continue;
            }
            //扩列
            returnwords[*returnSize] = (char *)malloc(sizeof(words[i]));
            memset(returnwords[*returnSize], 0, sizeof(words[i]));
            *returnSize++;
        }
        else
        {
            //扩列
            returnwords[*returnSize] = (char *)malloc(sizeof(words[i]));
            memset(returnwords[*returnSize], 0, sizeof(words[i]));
            *returnSize++;
        }   
    }
    return returnwords;
}


// @lc code=end

