/*
 * @lc app=leetcode.cn id=1266 lang=c
 *
 * [1266] 访问所有点的最小时间
 */

// @lc code=start


int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int tmp[2] = {0};
    tmp[0] = points[0][0];
    tmp[1] = points[0][1];
    int feet = 0, dx, dy;
    for(int i=1; i<pointsSize; ++i){
        dx = abs(points[i][0]-tmp[0]);
        dy = abs(points[i][1]-tmp[1]);
        feet += (abs(dx-dy) + (dx>dy?dy:dx));
        tmp[0] = points[i][0];
        tmp[1] = points[i][1];
    }
    return feet;
}


// @lc code=end

