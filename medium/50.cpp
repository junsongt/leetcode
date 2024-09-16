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

// 50. Pow(x, n)
/*
实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，x^n ）。
*/

// 特别问题： 整数溢出！！！

double myPow(double x, long long n) {
    if (n < 0) {
        return 1.0 / myPow(x, -n);
    }
    double res = 1.0;
    int i = 0;
    while (n > 0) {
        if (n & 1 == 1) {
            res *= x;
        }
        x = x * x;
        n = n >> 1;
    }
    return res;
}