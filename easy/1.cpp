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

// 1. 两数之和
/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
*/

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++) {
        auto it = dict.find(target - nums[i]);
        if (it != dict.end()) {
            res = {it->second, i};
            return res;
        }
        dict[nums[i]] = i;
    }
    return {};
}