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

// 125. 验证回文串
/*
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
*/

bool isPalindrome(string s) {
    int k = 0;
    while (k < s.length()) {
        if (!isalpha(s[k]) && !isdigit(s[k])) {
            s.erase(s.begin() + k);
        } else {
            k++;
        }
    }
    bool res = true;
    int i = 0;
    int n = s.length();
    int stop;
    if (n % 2 == 0) {
        stop = n / 2;
    } else {
        stop = (n - 1) / 2;
    }
    char c = tolower(s[i]);
    while (i < stop && c == tolower(s[n - 1 - i])) {
        i++;
        c = tolower(s[i]);
    }
    if (i != stop) {
        res = false;
    }
    return res;
}