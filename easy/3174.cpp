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

// 3174. 清除数字
/*
给你一个字符串 s 。

你的任务是重复以下操作删除 所有 数字字符：

删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
请你返回删除所有数字字符以后剩下的字符串。
*/

string clearDigits(string s) {
    int parser = 0;

    while (parser < s.size()) {
        if (isdigit(s[parser])) {
            s.erase(s.begin() + parser);
            // 如果parser在中间并且前面有字母， 删掉数字后parser移到后一位上，index不变， 但继续删掉前面字母后，parser对应的index要减1
            if (parser != 0 && isalpha(s[parser - 1])) {
                s.erase(s.begin() + parser - 1);
                parser--;
            }
        } else {
            parser++;
        }
    }
    return s;
}