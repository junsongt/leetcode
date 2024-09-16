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

// 14. 最长公共前缀

/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/

string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    int n = strs.size();
    int parser = 0;
    int word_idx = parser % n;
    int digit_idx = parser / n;
    char ref = strs[0][digit_idx];
    char curr = strs[word_idx][digit_idx];
    while (curr == ref && digit_idx < strs[word_idx].length()) {
        parser++;
        word_idx = parser % n;
        digit_idx = parser / n;
        if (word_idx == 0) {
            res += ref;
            ref = strs[0][digit_idx];
        }
        curr = strs[word_idx][digit_idx];
    }
    return res;
}