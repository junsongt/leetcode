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

// 3175. 找到连续赢 K 场比赛的第一位玩家
/*
有 n 位玩家在进行比赛，玩家编号依次为 0 到 n - 1 。

给你一个长度为 n 的整数数组 skills 和一个 正 整数 k ，其中 skills[i] 是第 i 位玩家的技能等级。skills 中所有整数 互不相同 。

所有玩家从编号 0 到 n - 1 排成一列。

比赛进行方式如下：

队列中最前面两名玩家进行一场比赛，技能等级 更高 的玩家胜出。
比赛后，获胜者保持在队列的开头，而失败者排到队列的末尾。
这个比赛的赢家是 第一位连续 赢下 k 场比赛的玩家。

请你返回这个比赛的赢家编号。
*/

int findWinningPlayer(vector<int>& skills, int k) {
    int n = skills.size();
    int count = 0;
    int i = 0;      // start pos when the subsequent nums are < skills[i]
    int j = 0;      // parser starting from i+1 for counting the counts
    int M_idx = 0;  // the index for the max in skills, if no one else before M wins k, then M is the only one who can win k
    while (i < n) {
        j = i + 1;
        while (j < n && skills[j] < skills[i] && count < k) {
            count++;
            j++;
        }
        if (j < n) {
            if (count == k) {
                return i;
            } else {
                count = 1;  // since skills[i] loses to skills[j], skills[j] got one point
            }
        }
        M_idx = i;
        i = j;
    }
    return M_idx;
}