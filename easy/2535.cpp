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

// 2535. 数组元素和与数字和的绝对差
/*
给你一个正整数数组 nums 。

元素和 是 nums 中的所有元素相加求和。
数字和 是 nums 中每一个元素的每一数位（重复数位需多次求和）相加求和。
返回 元素和 与 数字和 的绝对差。

注意：两个整数 x 和 y 的绝对差定义为 |x - y| 。
*/

int digit_sum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}
int differenceOfSum(vector<int>& nums) {
    int sum_1 = 0;
    int sum_2 = 0;
    for (int x : nums) {
        sum_1 += x;
        sum_2 += digit_sum(x);
    }

    return abs(sum_1 - sum_2);
}