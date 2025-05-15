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

// 1025. 除数博弈
/*
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

最初，黑板上有一个数字 n 。在每个玩家的回合，玩家需要执行以下操作：

选出任一 x，满足 0 < x < n 且 n % x == 0 。
用 n - x 替换黑板上的数字 n 。
如果玩家无法执行这些操作，就会输掉游戏。

只有在爱丽丝在游戏中取得胜利时才返回 true 。假设两个玩家都以最佳状态参与游戏。
*/

bool divisorGame(int n) {
    vector<bool> dp(n + 1, false);  // dp[i] = true: starts from number i and must win
    dp[0] = false, dp[1] = false;
    dp[2] = true;
    for (int i = 3; i <= n; i++) {
        int d = 1;  // enumerate divisor of i
        bool stop = false;
        while (d < i && !stop) {
            // if Alice picks d, then Bob starts at i-d and he must lose
            if (i % d == 0 && dp[i - d] == false) {
                dp[i] = true;
                stop = true;
            }
            d++;
        }
    }
    return dp[n];
}