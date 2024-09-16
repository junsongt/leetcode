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

// 2390. 从字符串中移除星号

/*
给你一个包含若干星号 * 的字符串 s 。

在一步操作中，你可以：

选中 s 中的一个星号。
移除星号 左侧 最近的那个 非星号 字符，并移除该星号自身。
返回移除 所有 星号之后的字符串。

注意：

生成的输入保证总是可以执行题面中描述的操作。
可以证明结果字符串是唯一的。
*/

string removeStars(string s) {
    int i = 0;
    while (i < s.length()) {
        // remove single * does not change index
        if (i == 0 && s[i] == '*') {
            s.erase(i, 1);
        }
        // remove a* together, the index falls back 1
        else if (i > 0 && s[i] == '*') {
            s.erase(i - 1, 2);
            i = i - 1;
        } else {
            i++;
        }
    }
    return s;
}