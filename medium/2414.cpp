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

// 2414. 最长的字母序连续子字符串的长度
/*
字母序连续字符串 是由字母表中连续字母组成的字符串。换句话说，字符串 "abcdefghijklmnopqrstuvwxyz" 的任意子字符串都是 字母序连续字符串 。

例如，"abc" 是一个字母序连续字符串，而 "acb" 和 "za" 不是。
给你一个仅由小写英文字母组成的字符串 s ，返回其 最长 的 字母序连续子字符串 的长度。
*/

int longestContinuousSubstring(string s) {
    int n = s.length();
    int l = 0;  // left parser for the starting point for counting consecutive char
    int r = 0;  // right parser for the counting
    int max_length = 1;
    int temp = 1;
    char prev = s[0];
    while (r < n) {
        char curr = s[r];
        // if continuous, move right parser, keep start still
        if (curr - prev == 1) {
            prev = curr;
            r++;
            temp++;
            // check boundary, update max for continuity
            if (r == n) {
                max_length = max(max_length, temp);
            }
        }
        // if not, update max, set left to current pos, and increment right parser
        else {
            max_length = max(max_length, temp);
            l = r;
            prev = curr;
            temp = 1;
            r++;
            // no need to check the boundary since if discontinuity occur at the end, then it has length 1, which is <= max_length
        }
    }
    return max_length;
}