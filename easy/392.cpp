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

// 392. 判断子序列
/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
*/

bool isSubsequence(string s, string t) {
    int m = s.length();
    int n = t.length();
    int ps = 0;
    int pt = 0;
    while (ps < m) {
        while (pt < n && s[ps] != t[pt]) {
            pt++;
        }
        if (pt == n && ps <= m - 1) {
            return false;
        } else {
            ps++;
            pt++;
        }
    }
    return true;
}