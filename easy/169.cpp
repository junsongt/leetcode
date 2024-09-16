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

// 169. 多数元素
// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> dict;
    int res;
    for (int x : nums) {
        auto it = dict.find(x);
        if (it == dict.end()) {
            dict[x] = 1;
        } else {
            (it->second)++;
        }
        int count = dict.find(x)->second;
        if (count > floor(n / 2)) {
            res = x;
        }
    }
    return res;
}