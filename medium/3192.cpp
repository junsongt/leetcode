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

// 3192. 使二进制数组全部等于 1 的最少操作次数 II
/*
给你一个二进制数组 nums 。

你可以对数组执行以下操作 任意 次（也可以 0 次）：

选择数组中 任意 一个下标 i ，并将从下标 i 开始一直到数组末尾 所有 元素 反转 。
反转 一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。

请你返回将 nums 中所有元素变为 1 的 最少 操作次数。
*/

/*
if the current digit flips, then all the digits after will flip, but all the previous digits don't flip. So the later, the more flips
But for a pointer parsing at each digit, the current value = original value + 1 * number of flips (mod 2), i.e. cv = ov + 1*k (mod 2). eg. originally, nums[i] = 0, then after 3 filps, then current value of nums[i] = 1 (0->1->0->1)
we don't actually do the flip for the tails, but we "predict" what each digit will be after k flips when we come to this digit, then change it to 1.
If current value of nums[i] = 0, then flip, so counter++, and also set original nums[i] = 1
If current value of nums[i] = 1, then just the original nums[i] = 1
*/
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int times = 0;  // cumulative digit changeing times
    for (int i = 0; i < n; i++) {
        if ((nums[i] + 1 * times) % 2 == 0) {
            nums[i] = 1;
            times++;
        } else {
            nums[i] = 1;
        }
    }
    if (nums[n - 1] == 1) {
        return times;
    } else {
        return -1;
    }
}