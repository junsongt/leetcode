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

// 3146. 两个字符串的排列差
/*
给你两个字符串 s 和 t，每个字符串中的字符都不重复，且 t 是 s 的一个排列。

排列差 定义为 s 和 t 中每个字符在两个字符串中位置的绝对差值之和。

返回 s 和 t 之间的 排列差 。
*/

int findPermutationDifference(string s, string t) {
    unordered_map<char, int> dict;
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (dict.find(c) == dict.end()) {
            dict[c] = i;
        }
    }
    for (int i = 0; i < t.length(); i++) {
        char d = t[i];
        int j = dict.find(d)->second;
        res += abs(i - j);
    }
    return res;
}