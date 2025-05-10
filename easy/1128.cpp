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

// 1128. 等价多米诺骨牌对的数量
/*
给你一组多米诺骨牌 dominoes 。

形式上，dominoes[i] = [a, b] 与 dominoes[j] = [c, d] 等价 当且仅当 (a == c 且 b == d) 或者 (a == d 且 b == c) 。即一张骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。



示例 1：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1
示例 2：

输入：dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
输出：3
*/

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int res = 0;
    unordered_map<string, int> dict;
    for (int i = 0; i < dominoes.size(); i++) {
        string digit1 = to_string(dominoes[i][0]);
        string digit2 = to_string(dominoes[i][1]);
        string key = digit1 + digit2;
        string key_flip = digit2 + digit1;
        auto it = dict.find(key);
        auto it_flip = dict.find(key_flip);
        if (it == dict.end() && it_flip == dict.end()) {
            dict[key] = 1;
        } else {
            if (it != dict.end()) {
                (it->second)++;
            } else {
                (it_flip->second)++;
            }
        }
    }
    for (auto it = dict.begin(); it != dict.end(); it++) {
        int cnt = it->second;
        if (cnt > 1) {
            res += (cnt - 1) * cnt / 2;
        }
    }
    return res;
}
