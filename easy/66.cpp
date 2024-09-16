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

// 66. 加一
/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;
    int d = digits[i];
    digits[i] = d + 1;
    while (d + 1 > 9 && i >= 0) {
        digits[i] -= 10;
        i--;
        if (i >= 0) {
            d = digits[i];
            digits[i] = d + 1;
        }
    }
    if (digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}