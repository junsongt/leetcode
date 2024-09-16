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

// 219. 存在重复元素 II

/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
*/

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        if (dict.find(curr) == dict.end()) {
            dict[curr] = i;
        } else {
            auto it = dict.find(curr);
            if (abs(i - it->second) <= k) {
                return true;
            } else {
                dict[curr] = i;
            }
        }
    }
    return false;
}