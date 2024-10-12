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

// 3158. 求出出现两次数字的 XOR 值
/*
给你一个数组 nums ，数组中的数字 要么 出现一次，要么 出现两次。

请你返回数组中所有出现两次数字的按位 XOR 值，如果没有数字出现过两次，返回 0 。
*/
int duplicateNumbersXOR(vector<int>& nums) {
    vector<int> stat(50);
    int res = 0;
    for (int x : nums) {
        stat[x - 1]++;
        if (stat[x - 1] == 2) {
            res ^= x;
        }
    }
    return res;
}