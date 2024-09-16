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

// 121. 买卖股票的最佳时机
/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;

    int i = 1;
    int prev = prices[i - 1];
    int curr = prices[i];
    int temp = 0;
    int start = prices[0];
    while (i < prices.size()) {
        curr = prices[i];
        prev = prices[i - 1];
        if (curr < prev) {
            if (curr < start) {
                start = curr;
                temp = 0;
            }
            i++;
        } else {
            temp = curr - start;
            if (temp > maxProfit) {
                maxProfit = temp;
            }
            i++;
        }
    }
    return maxProfit;
}