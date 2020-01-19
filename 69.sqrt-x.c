/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start


int mySqrt(int x){
    if(x<=0) return 0;
    long r = x;
    while(r*r>x){
        r = (r+x/r)/2;
    }
    return r;
}


// @lc code=end

