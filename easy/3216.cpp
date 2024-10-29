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

// 3216. 交换后字典序最小的字符串
/*
给你一个仅由数字组成的字符串 s，在最多交换一次 相邻 且具有相同 奇偶性 的数字后，返回可以得到的
字典序最小的字符串
。

如果两个数字都是奇数或都是偶数，则它们具有相同的奇偶性。例如，5 和 9、2 和 4 奇偶性相同，而 6 和 9 奇偶性不同。
*/

string getSmallestString(string s) {
    int n = s.length();
    int i = 0;
    int curr = s[i] - '0';
    int next = s[i + 1] - '0';
    bool exchange = false;

    while (i < n - 1 && !exchange) {
        if ((curr % 2 == 0 && next % 2 == 0) || (curr % 2 == 1 && next % 2 == 1)) {
            if (curr > next) {
                char temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                exchange = true;
            }
        }
        i++;
        curr = s[i] - '0';
        next = s[i + 1] - '0';
    }
    return s;
}