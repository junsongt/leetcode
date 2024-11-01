#include <time.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

// 3226. 使两个整数相等的位更改次数
/*
给你两个正整数 n 和 k。

你可以选择 n 的 二进制表示 中任意一个值为 1 的位，并将其改为 0。

返回使得 n 等于 k 所需要的更改次数。如果无法实现，返回 -1。

*/

int minChanges(int n, int k) {
    int count = 0;
    while (n != k) {
        if ((n & 1) == 1 && (k & 1) == 0) {
            count++;
        } else if ((n & 1) == 0 && (k & 1) == 1) {
            return -1;
        }
        n = n >> 1;
        k = k >> 1;
    }
    return count;
}