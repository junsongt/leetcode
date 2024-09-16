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

// 69. x 的平方根
/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/

int mySqrt(int x) {
    // Newton
    // f(u) = u^2 - x;
    // u_{n+1} = u_n - f(u_n) / f'(u_n)
    long x0 = x;
    while (x0 * x0 > x) {
        x0 = (x0 + x / x0) / 2;
    }
    return (int)x0;
}