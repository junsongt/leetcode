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

// 67. 二进制求和
/*
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
*/

string addBinary(string a, string b) {
    int n1 = a.length();
    int n2 = b.length();

    int m = max(n1, n2);

    // temporary sum when digit forwards
    int temp = 0;
    string res = "";
    for (int i = 0; i < m; i++) {
        int d1;
        int d2;
        if (i < n1 && i < n2) {
            d1 = (int)a[n1 - 1 - i] - '0';
            d2 = (int)b[n2 - 1 - i] - '0';
        } else if (i < n1 && i >= n2) {
            d1 = (int)a[n1 - 1 - i] - '0';
            d2 = 0;
        } else {
            d1 = 0;
            d2 = (int)b[n2 - 1 - i] - '0';
        }
        if (temp + d1 + d2 == 0) {
            res = '0' + res;
            temp = 0;
        } else if (temp + d1 + d2 == 1) {
            res = '1' + res;
            temp = 0;
        } else if (temp + d1 + d2 == 2) {
            res = '0' + res;
            temp = 1;
        } else {
            res = '1' + res;
            temp = 1;
        }
    }
    if (temp == 0) {
        return res;
    } else {
        return '1' + res;
    }
    return res;
}