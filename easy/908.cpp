#include <time.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

// 908. 最小差值 I
/*
给你一个整数数组 nums，和一个整数 k 。

在一个操作中，您可以选择 0 <= i < nums.length 的任何索引 i 。将 nums[i] 改为 nums[i] + x ，其中 x 是一个范围为 [-k, k] 的任意整数。对于每个索引 i ，最多 只能 应用 一次 此操作。

nums 的 分数 是 nums 中最大和最小元素的差值。

在对  nums 中的每个索引最多应用一次上述操作后，返回 nums 的最低 分数 。
*/
/*
Goal is to make every num[i] as close as possible, so try to make max close to min, if |max-min| > 2k, then can't make them even; otherwise, possible.
*/
int smallestRangeI(vector<int>& nums, int k) {
    int n = nums.size();
    int M = nums[0];
    int m = nums[0];

    for (int i = 0; i < n; i++) {
        m = min(m, nums[i]);
        M = max(M, nums[i]);
    }
    if (M - m < 2 * k) {
        return 0;
    } else {
        return M - m - 2 * k;
    }
}