/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start

/* 笨拙的解法
bool isPalindrome(int x){
    if(0==x) return true;
    if(x<0 || x%10 ==0 )
    {
        return false;
    }

    int tmp, i, renum=0;
    int num[12] = {0};
    
    for(i=0, tmp=x; tmp>0; tmp/=10, ++i)
    {
        num[i] = tmp%10;
    }

    for(tmp=0; --i>=0; ++tmp)
    {
        renum += num[i] * pow(10, tmp);
    }
    if(x == renum)
    {
        return true;
    }

    return false;
}
*/

bool isPalindrome(int x){
    //直接筛掉负数和个位为0的数且不许考虑溢出
    if(x<0 || (x%10==0 && x!=0) )
    {
        return false;
    }

    int a = 0;
    //只需要比较一半的数字
    while(x > a){
        a = a * 10 + x%10;
        x /= 10;
    }
    // 12 == 123 || 12 == 123/10
    return a == x || x == a/10;
}

// @lc code=end

