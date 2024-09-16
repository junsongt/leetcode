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

// LCP 40. 心算挑战
// 「力扣挑战赛」心算项目的挑战比赛中，要求选手从 N 张卡牌中选出 cnt 张卡牌，若这 cnt 张卡牌数字总和为偶数，则选手成绩「有效」且得分为 cnt 张卡牌数字总和。 给定数组 cards 和 cnt，其中 cards[i] 表示第 i 张卡牌上的数字。 请帮参赛选手计算最大的有效得分。若不存在获取有效得分的卡牌方案，则返回 0。
int maximumScore(vector<int>& cards, int cnt) {
    sort(cards.begin(), cards.end());
    int ans = 0;
    int temp = 0;
    int odd, even = -1;
    int end = cards.size() - cnt;
    for (int i = cards.size() - 1; i >= end; i--) {
        temp += cards[i];
        if (cards[i] % 2 != 0) {
            odd = cards[i];
        } else {
            even = cards[i];
        }
    }

    if (temp % 2 == 0) {
        return temp;
    }

    for (int i = cards.size() - cnt - 1; i >= 0; i--) {
        if (cards[i] & 1) {
            if (even != -1) {
                ans = max(ans, temp - even + cards[i]);
            }
        } else {
            if (odd != -1) {
                ans = max(ans, temp - odd + cards[i]);
            }
        }
    }
    return ans;
}