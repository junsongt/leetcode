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

// 2708. 一个小组的最大实力值
/*
给你一个下标从 0 开始的整数数组 nums ，它表示一个班级中所有学生在一次考试中的成绩。老师想选出一部分同学组成一个 非空 小组，且这个小组的 实力值 最大，如果这个小组里的学生下标为 i0, i1, i2, ... , ik ，那么这个小组的实力值定义为 nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​] 。

请你返回老师创建的小组能得到的最大实力值为多少。
*/

// DP solution
long long maxStrength(vector<int>& nums) {
    long long mx = nums[0];
    long long mn = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        long long temp = mx;
        mx = max(max(mx, nums[i] * 1LL), max(mx * nums[i], mn * nums[i]));
        mn = min(min(mn, nums[i] * 1LL), min(temp * nums[i], mn * nums[i]));
    }
    return mx;
}

// long long maxStrength(vector<int> nums) {
//     int n = nums.size();
//     long long mx = nums[0], mn = nums[0];
//     for (int i = 1; i < n; ++i) {
//         long long p1 = mx * nums[i] * 1LL;
//         long long p2 = mn * nums[i] * 1LL;
//         mx = max(mx, max(max(p1,p2), nums[i]*1LL));
//         mn = min(mn, min(min(p1,p2), nums[i]*1LL));
//     }
//     return mx;
// }