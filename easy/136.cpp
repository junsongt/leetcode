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

// 136. 只出现一次的数字
/*
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
*/

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int x : nums) {
        // XOR("^") makes two identical terms into 0, and 0 XOR a = a
        res ^= x;
    }
    return res;
}