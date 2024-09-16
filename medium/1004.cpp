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

// 1004. 最大连续1的个数 III
/*
给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。
*/

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0;
    int res = 0;
    int zeros = 0;

    for (int r = 0; r < n; r++) {
        if (nums[r] == 0) {
            zeros++;
        }

        while (l <= r && zeros > k) {
            if (nums[l] == 0) {
                zeros--;
            }
            l++;
        }

        res = max(res, r - l + 1);
    }
    return res;
}