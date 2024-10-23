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

// 3185. 构成整天的下标对数目 II
/*
给你一个整数数组 hours，表示以 小时 为单位的时间，返回一个整数，表示满足 i < j 且 hours[i] + hours[j] 构成 整天 的下标对 i, j 的数目。

整天 定义为时间持续时间是 24 小时的 整数倍 。

例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。
*/

long long countCompleteDayPairs(vector<int>& hours) {
    long long res = 0;
    vector<long long> stat(24);  // index is modulo number, and value is counts
    /*
    if x = k (mod 24), then we should find how many numbers before x are (24-k) (mod 24)
    but if k = 0, we should find how many are 24 (mod 24) = 0 (mod 24)
    start computing result before counting the frequency because otherwise when the first number gets counted, then the first one will be considered a pair with itself. So naturally, find the numbers before x first, then update the stat.
    */
    for (int x : hours) {
        res += stat[(24 - x % 24) % 24];
        stat[x % 24]++;
    }
    return res;
}