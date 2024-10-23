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

// 17. 电话号码的字母组合
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

vector<string> augpaste(vector<string> V, string str) {
    vector<string> res;
    // augment & paste
    for (char c : str) {
        for (string s : V) {
            string ss = s + c;
            res.push_back(ss);
        }
    }
    return res;
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    unordered_map<int, string> chart;
    chart[2] = "abc";
    chart[3] = "def";
    chart[4] = "ghi";
    chart[5] = "jkl";
    chart[6] = "mno";
    chart[7] = "pqrs";
    chart[8] = "tuv";
    chart[9] = "wxyz";

    for (char c : digits) {
        int d = c - '0';
        string str = chart.find(d)->second;

        if (res.empty()) {
            for (char ch : str) {
                string s(1, ch);
                res.push_back(s);
            }
        } else {
            res = augpaste(res, str);
        }
    }
    return res;
}