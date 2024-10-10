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

// 2516. 每种字符至少取 K 个
/*
给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k 。每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。

你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 -1 。
*/

int takeCharacters(string s, int k) {
    int n = s.size();
    vector<int> stat(3);
    if (k == 0) return 0;
    for (char c : s) {
        if (c == 'a') stat[0]++;
        if (c == 'b') stat[1]++;
        if (c == 'c') stat[2]++;
    }
    if (stat[0] < k || stat[1] < k || stat[2] < k) return -1;

    int r_a = stat[0];
    int r_b = stat[1];
    int r_c = stat[2];
    int l_a = 0;
    int l_b = 0;
    int l_c = 0;
    int res = n;
    int r = 0;

    int num_from_right = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && ((l_a + r_a) >= k && (l_b + r_b) >= k && (l_c + r_c) >= k)) {
            if (s[r] == 'a') r_a--;
            if (s[r] == 'b') r_b--;
            if (s[r] == 'c') r_c--;
            r++;
        }
        if (r == n && ((l_a + r_a) >= k && (l_b + r_b) >= k && (l_c + r_c) >= k)) {
            num_from_right = 0;
        } else {
            num_from_right = n - (r - 1);
        }

        res = min(res, l + num_from_right);
        if (s[l] == 'a') l_a++;
        if (s[l] == 'b') l_b++;
        if (s[l] == 'c') l_c++;
    }
    return res;
}