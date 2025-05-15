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

// 119. 杨辉三角 II
/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/
vector<int> getRow(int rowIndex) {
    vector<vector<int>> dp;
    dp.push_back({1});
    if (rowIndex == 0) {
        return dp[rowIndex];
    }
    for (int i = 1; i <= rowIndex; i++) {
        // row number is i+1, so number of elements = i+1
        dp.emplace_back(i + 1);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[rowIndex];
}