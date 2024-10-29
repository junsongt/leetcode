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

// 3211. 生成不含相邻零的二进制字符串
/*
给你一个正整数 n。

如果一个二进制字符串 x 的所有长度为 2 的
子字符串
中包含 至少 一个 "1"，则称 x 是一个 有效 字符串。

返回所有长度为 n 的 有效 字符串，可以以任意顺序排列。
*/

vector<string> validStrings(int n) {
    vector<string> paths = {"0", "1"};
    int l = 1;
    while (l < n) {
        vector<string> additional;
        for (string& path : paths) {
            if (path[l - 1] == '0') {
                path += '1';
            } else {
                string twin = path;
                path += '0';
                additional.push_back(twin + '1');
            }
        }
        paths.insert(paths.end(), additional.begin(), additional.end());
        l++;
    }
    return paths;
}