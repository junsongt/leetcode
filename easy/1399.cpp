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

// 1399. 统计最大组的数目
/*
给定一个整数 n 。

我们需要根据数字的数位和将 1 到 n 的数字分组。例如，数字 14 和 5 属于 同一 组，而数字 13 和 3 属于 不同 组。

返回最大组的数字数量，即元素数量 最多 的组。
*/
int digitsum(int x) {
    int s = 0;
    while (x != 0) {
        s += x % 10;
        x = x / 10;
    }
    return s;
}

int countLargestGroup(int n) {
    unordered_map<int, int> dict;
    int max_group = 0;
    for (int num = 1; num <= n; num++) {
        // compute digit sum of each num and classify it into freq
        int s = digitsum(num);
        auto it = dict.find(s);
        if (it == dict.end()) {
            dict[s] = 1;
        }
        else {
            (it->second)++;
        }
        max_group = max(max_group, dict[s]);
    }
    int res = 0;
    for (auto it = dict.begin(); it != dict.end(); it++) {
        if ((it->second) == max_group) {
            res++;
        } 
    }
    return res; 
}
