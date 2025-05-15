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

// 746. 使用最小花费爬楼梯
/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。
*/

// forward dp
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1);  // dp[i]:= min cost reaching ith step
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
}

// // backward dp
// int minCostClimbingStairs(vector<int>& cost) {
//     int n = cost.size();
//     vector<int> dp(n+1); // dp[i]:= min cost starting from ith step
//     dp[n] = 0;
//     dp[n-1] = cost[n-1];
//     for (int i = n-2; i >= 0; i--) {
//         dp[i] = min(cost[i]+dp[i+1], cost[i]+dp[i+2]);
//     }
//     return min(dp[0], dp[1]);
// }
