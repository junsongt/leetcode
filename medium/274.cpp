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

// 274. H 指数

/*
给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。

根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个。
*/

int hIndex(vector<int>& citations) {
    int max_idx = 0;
    int n = citations.size();
    sort(citations.begin(), citations.end());
    for (int i = 0; i < n; i++) {
        // at i, there are (n-i) papers that have >= c_i quotations;
        // h = min{c_i, n-i} s.t. h <= c_i & h <= n-i
        int h = min(n - i, citations[i]);
        if (h > max_idx) {
            max_idx = h;
        }
    }
    return max_idx;
}