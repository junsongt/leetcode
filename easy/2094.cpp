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

// 2094. 找出 3 位偶数
/*
给你一个整数数组 digits ，其中每个元素是一个数字（0 - 9）。数组中可能存在重复元素。

你需要找出 所有 满足下述条件且 互不相同 的整数：

该整数由 digits 中的三个元素按 任意 顺序 依次连接 组成。
该整数不含 前导零
该整数是一个 偶数
例如，给定的 digits 是 [1, 2, 3] ，整数 132 和 312 满足上面列出的全部条件。

将找出的所有互不相同的整数按 递增顺序 排列，并以数组形式返回。
*/
vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> res;
    vector<int> dict(10, 0);
    for (int i = 0; i < digits.size(); i++) {
        dict[digits[i]]++;
    }
    for (int num = 100; num < 1000; num++) {
        vector<int> freq(10, 0);
        int temp = num;
        for (int j = 2; j >= 0; j--) {
            int d = temp / pow(10, j);
            temp = temp - d * pow(10, j);
            freq[d]++;
        }
        bool contain = true;
        for (int k = 0; k < 10; k++) {
            if (freq[k] > dict[k]) {
                contain = false;
            }
        }
        if (contain && num % 2 == 0) {
            res.push_back(num);
        }
    }
    return res;
}
