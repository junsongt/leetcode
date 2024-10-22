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

// 910. 最小差值 II
/*
给你一个整数数组 nums，和一个整数 k 。

对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成 nums[i] + k 或 nums[i] - k 。

nums 的 分数 是 nums 中最大元素和最小元素的差值。

在更改每个下标对应的值之后，返回 nums 的最小 分数 。
*/

int smallestRangeII(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int M = nums[n - 1];  // original maximum
    int m = nums[0];      // original minimum
    int res = M - m;      // initial difference, the biggest
    for (int i = 0; i < n - 1; i++) {
        int a = nums[i];
        int b = nums[i + 1];
        /*
        given x[i] <= x[i+1]:
        we know (x[i]-k, x[i+1]+k) could only make difference bigger, so consider (x[i]+k, x[i+1]-k) case, and thus surely in the end: m->m+k and M->M-k
        dynamic_max >= M-k >= x[i+1]-k and dynamic_max >= x[i]+k
        dynamic_min <= m+k <= x[i]+k and dynamic_min <= x[i+1]-k
        */
        int dynamic_max = max(a + k, M - k);
        int dynamic_min = min(m + k, b - k);
        res = min(res, dynamic_max - dynamic_min);
    }
    return res;
}