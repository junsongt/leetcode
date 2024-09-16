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

// 2576. 求出最多标记下标
/*
给你一个下标从 0 开始的整数数组 nums 。

一开始，所有下标都没有被标记。你可以执行以下操作任意次：

选择两个 互不相同且未标记 的下标 i 和 j ，满足 2 * nums[i] <= nums[j] ，标记下标 i 和 j 。
请你执行上述操作任意次，返回 nums 中最多可以标记的下标数目。
*/

int maxNumOfMarkedIndices(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;
    int l = 0;
    int r = (n - 1) / 2 + 1;
    while (l <= (n - 1) / 2 && r < n) {
        if (2 * nums[l] <= nums[r]) {
            l++;
            r++;
            count += 2;
        } else {
            r++;
        }
    }
    return count;
}