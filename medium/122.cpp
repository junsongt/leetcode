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

// 122. 买卖股票的最佳时机 II
/*
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/

int maxProfit(vector<int>& prices) {
    int accum = 0;

    int i = 1;
    int prev;
    int curr;

    while (i < prices.size()) {
        curr = prices[i];
        prev = prices[i - 1];
        if (curr >= prev) {
            accum += curr - prev;
        }
        i++;
    }
    return accum;
}