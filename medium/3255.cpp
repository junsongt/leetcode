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

// 3255. 长度为 K 的子数组的能量值 II
/*
给你一个长度为 n 的整数数组 nums 和一个正整数 k 。

一个数组的 能量值 定义为：

如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。
否则为 -1 。
你需要求出 nums 中所有长度为 k 的
子数组
 的能量值。

请你返回一个长度为 n - k + 1 的整数数组 results ，其中 results[i] 是子数组 nums[i..(i + k - 1)] 的能量值。
*/

vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res(n - k + 1, -1);
    ;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i] - nums[i - 1] != 1) {
            count = 1;
        } else {
            count++;
        }
        if (count >= k) {
            res[i - k + 1] = nums[i];
        }
    }
    return res;
}