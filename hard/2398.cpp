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

// 2398. 预算内的最多机器人数目
/*
你有 n 个机器人，给你两个下标从 0 开始的整数数组 chargeTimes 和 runningCosts ，两者长度都为 n 。第 i 个机器人充电时间为 chargeTimes[i] 单位时间，花费 runningCosts[i] 单位时间运行。再给你一个整数 budget 。

运行 k 个机器人 总开销 是 max(chargeTimes) + k * sum(runningCosts) ，其中 max(chargeTimes) 是这 k 个机器人中最大充电时间，sum(runningCosts) 是这 k 个机器人的运行时间之和。

请你返回在 不超过 budget 的前提下，你 最多 可以 连续 运行的机器人数目为多少。
*/

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    int n = chargeTimes.size();
    int res = 0;
    int l = 0;
    int max_time = 0;
    long long cost = 0;

    for (int r = 0; r < n; r++) {
        max_time = max(max_time, chargeTimes[r]);
        cost += runningCosts[r];
        while (l <= r && max_time + (r - l + 1) * cost > budget) {
            cost -= runningCosts[l];
            if (chargeTimes[l] == max_time) {
                int submax = 0;
                for (int i = l + 1; i <= r; i++) {
                    submax = max(submax, chargeTimes[i]);
                }
                max_time = submax;
            }
            l++;
        }
        res = max(res, r - l + 1);
    }
    return res;
}