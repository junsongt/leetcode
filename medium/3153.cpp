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

// 3153. 所有数对中数位差之和
/*
你有一个数组 nums ，它只包含 正 整数，所有正整数的数位长度都 相同 。

两个整数的 数位差 指的是两个整数 相同 位置上不同数字的数目。

请你返回 nums 中 所有 整数对里，数位差之和。
*/

long long sumDigitDifferences(vector<int>& nums) {
    long long res = 0;
    int n = nums.size();

    // find the length of every integer
    int m = floor(log10(nums[0])) + 1;

    unordered_map<int, int> dict;
    for (int i = 0; i <= 9; i++) {
        dict[i] = 0;
    }

    // position by position, from left to right, 10^(m-1), 10^(m-2),...
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int x = nums[j];
            int digit = x / pow(10, i);
            auto it = dict.find(digit);
            it->second++;
            nums[j] = nums[j] - digit * pow(10, i);
        }
        long long sum = 0;
        for (auto& pair : dict) {
            long long c = pair.second;
            sum += c * (n - c);
            pair.second = 0;
        }
        res += sum / 2;
    }
    return res;
}