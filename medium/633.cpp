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

// 633. 平方数之和
/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
*/

bool judgeSquareSum(int c) {
    bool found = false;
    long a = 0;
    long a_sq = a * a;
    while (!found && a_sq <= c) {
        double b = sqrt(c - a_sq);
        if (b == int(b)) {
            found = true;
        }
        a++;
        a_sq = a * a;
    }
    return found;

    // // double pointers
    // bool found = false;
    // long long a = 0;
    // long long b = sqrt(c);
    // while (!found && a <= b) {
    //     long long temp = a * a + b * b;
    //     if (temp == c) {
    //         found = true;
    //     } else if (temp < c) {
    //         a++;
    //     } else {
    //         b--;
    //     }
    // }
    // return found;
}