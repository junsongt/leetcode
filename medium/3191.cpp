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

// 3191. 使二进制数组全部等于 1 的最少操作次数 I
/*
给你一个二进制数组 nums 。

你可以对数组执行以下操作 任意 次（也可以 0 次）：

选择数组中 任意连续 3 个元素，并将它们 全部反转 。
反转 一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。

请你返回将 nums 中所有元素变为 1 的 最少 操作次数。如果无法全部变成 1 ，返回 -1 。
*/

/*
(1) If nums[0] is 0, then the only way to change it to 1 is by doing an operation on the first 3 elements of the array.
(2) After Changing nums[0] to 1, use the same logic on the remaining array.
*/

int minOperations(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int sum = 0;
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] == 0) {
            nums[i] = 1;
            nums[i + 1] = 1 - nums[i + 1];
            nums[i + 2] = 1 - nums[i + 2];
            res++;
        }
        sum++;
    }
    sum = sum + nums[n - 2] + nums[n - 1];
    if (sum == n) {
        return res;
    } else {
        return -1;
    }
}