#include <time.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

// 3164. 优质数对的总数 II
/*
给你两个整数数组 nums1 和 nums2，长度分别为 n 和 m。同时给你一个正整数 k。

如果 nums1[i] 可以被 nums2[j] * k 整除，则称数对 (i, j) 为 优质数对（0 <= i <= n - 1, 0 <= j <= m - 1）。

返回 优质数对 的总数。
*/

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    long long res = 0;
    unordered_map<int, long long> count1, count2;
    int M = 0;
    // record the freq of each number in nums1, nums2
    for (int x : nums1) {
        count1[x]++;
        M = max(M, x);
    }
    for (int x : nums2) {
        count2[x]++;
    }
    for (auto kv : count2) {
        int v = kv.first;
        long long count = kv.second;
        // enumerate multiples of v*k as {vk, 2vk, 3vk, ..., M}
        for (int x = v * k; x <= M; x += v * k) {
            if (count1.find(x) != count1.end()) {
                res += count1[x] * count;
            }
        }
    }
    return res;
}