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

// 28. 找出字符串中第一个匹配项的下标

/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
*/

int strStr(string haystack, string needle) {
    int res;
    int start = 0;
    int parser = 0;
    int m = haystack.length();
    int n = needle.length();

    while (start < m - n + 1) {
        // parsing to check if it has needle, if not go on searching
        parser = 0;
        while (parser < n && haystack[start + parser] == needle[parser]) {
            parser++;
        }
        // if found
        if (parser == n) {
            return start;
        } else {
            start++;
        }
    }
    return -1;
}