#include <time.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

// 2848. 与车相交的点
/*
给你一个下标从 0 开始的二维整数数组 nums 表示汽车停放在数轴上的坐标。对于任意下标 i，nums[i] = [starti, endi] ，其中 starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。

返回数轴上被车 任意部分 覆盖的整数点的数目。
*/

int numberOfPoints(vector<vector<int>>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int lb = nums[0][0];
    int ub = nums[0][1];
    int count = ub - lb + 1;
    int i = 1;

    while (i < n) {
        int l = nums[i][0];
        int r = nums[i][1];
        // disjoint
        if (l > ub) {
            count += r - l + 1;
            lb = l;
            ub = r;
        }
        // intersect
        else if (l <= ub && r > ub) {
            count += r - ub;
            ub = r;
        }
        i++;
    }
    return count;
}