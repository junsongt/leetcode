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

// 191. 位1的个数

/*
编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中
设置位的个数（也被称为汉明重量）。
*/

int hammingWeight(int n) {
    int weight = 0;
    double expon = floor(log2(n));
    double remainder = n - pow(2.0, expon);
    while (remainder > 0) {
        weight++;
        n = remainder;
        expon = floor(log2(n));
        remainder = n - pow(2.0, expon);
    }
    return weight + 1;
}