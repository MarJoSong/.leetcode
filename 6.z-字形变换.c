/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start

char *convert(char *s, int numRows)
{
    char *p = s;
    char *pp = s;
    char *b = p;
    char *fstr = NULL;
    char *str;
    int i = 1;
    int len = 0;
    int first = 1;
    len = strlen(s);
    str = (char *)malloc(sizeof(char) * len + ((numRows - 1) * 2));
    fstr = str;
    for (i = numRows; numRows > 0; --numRows)
    {
        while (*p)
        {
            strncpy(str, p, 1);
            str++;
            p += (i - 1) * 2;
            if (numRows != 1 && i != numRows)
            {
                if (*pp && first)
                {
                    pp += (numRows - 1) * 2;
                    if (*pp)
                    {
                        strncpy(str, pp, 1);
                        str++;
                    }
                    first = 0;
                }
                else
                {
                    if (*pp)
                    {
                        pp += (i - 1) * 2;
                        if (*pp)
                        {
                            strncpy(str, pp, 1);
                            str++;
                        }
                    }
                }
            }
        }
        b++;
        p = b;
        pp = b;
        first = 1;
    }
    *str = '\0';
    return fstr;
}

// @lc code=end
