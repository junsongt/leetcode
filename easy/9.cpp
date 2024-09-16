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

// 9. 回文数
/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数
是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
*/

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    } else {
        bool res = true;
        std::string str = std::to_string(x);
        int i = 0;
        int n = str.length();
        int stop;
        if (n % 2 == 0) {
            stop = n / 2;
        } else {
            stop = (n - 1) / 2;
        }
        char c = str[i];
        while (c == str[n - 1 - i] && i < stop) {
            i++;
            c = str[i];
        }
        if (i != stop) {
            res = false;
        }
        return res;
    }
}