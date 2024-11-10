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

// 540. 有序数组中的单一元素
/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
*/

int singleNonDuplicate(vector<int>& nums) {
    // the length of nums must be odd since one singleton plus all the rest pairs
    int l = 0;
    int r = nums.size() - 1;
    int res = nums[0];
    bool found = false;

    while (l < r && !found) {
        int m = (l + r) / 2;
        if (m % 2 == 0) {
            if (nums[m - 1] == nums[m]) {
                r = m;
                m = (l + r) / 2;
            } else if (nums[m + 1] == nums[m]) {
                l = m;
                m = (l + r) / 2;
            } else {
                res = nums[m];
                found = true;
            }
        } else {
            if (nums[m - 1] == nums[m]) {
                l = m + 1;
                m = (l + r) / 2;
            } else if (nums[m + 1] == nums[m]) {
                r = m - 1;
                m = (l + r) / 2;
            }
        }
    }
    return (l >= r) ? nums[l] : res;
}