
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

// 137. 只出现一次的数字 II
/*
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
*/

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> dict;
    int res;
    for (int x : nums) {
        if (dict.find(x) == dict.end()) {
            dict[x] = 1;
        } else {
            (dict.find(x)->second)++;
        }
    }
    for (auto x : dict) {
        if (x.second == 1) {
            res = x.first;
            break;
        }
    }
    return res;
}