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

// 3194. 最小元素和最大元素的最小平均值
/*
你有一个初始为空的浮点数数组 averages。另给你一个包含 n 个整数的数组 nums，其中 n 为偶数。

你需要重复以下步骤 n / 2 次：

从 nums 中移除 最小 的元素 minElement 和 最大 的元素 maxElement。
将 (minElement + maxElement) / 2 加入到 averages 中。
返回 averages 中的 最小 元素。
*/

double minimumAverage(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums.size() - 1;
    double res = (nums[l] + nums[r]) * 1.0 / 2;
    while (l <= r) {
        res = min(res, (nums[l] + nums[r]) * 1.0 / 2);
        l++;
        r--;
    }
    return res;
}