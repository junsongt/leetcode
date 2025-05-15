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

// 118. 杨辉三角
/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> dp;
    dp.push_back({1});
    if (numRows == 1) {
        return dp;
    }
    for (int i = 1; i < numRows; i++) {
        // row number is i+1, so number of elements = i+1
        // vector<int> row(i+1);
        dp.emplace_back(i + 1);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                // row[j] = 1;
                dp[i][j] = 1;
            } else {
                // row[j] = dp[i-1][j-1] + dp[i-1][j];
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        // dp.push_back(row);
    }
    return dp;
}