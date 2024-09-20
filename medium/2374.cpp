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

// 2374. 边积分最高的节点
/*
给你一个有向图，图中有 n 个节点，节点编号从 0 到 n - 1 ，其中每个节点都 恰有一条 出边。

图由一个下标从 0 开始、长度为 n 的整数数组 edges 表示，其中 edges[i] 表示存在一条从节点 i 到节点 edges[i] 的 有向 边。

节点 i 的 边积分 定义为：所有存在一条指向节点 i 的边的节点的 编号 总和。

返回 边积分 最高的节点。如果多个节点的 边积分 相同，返回编号 最小 的那个。
*/

int edgeScore(vector<int>& edges) {
    int n = edges.size();
    vector<long long> stat(n);
    long long credit = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        // i is the start, j is destination
        int j = edges[i];
        stat[j] += i;  // now j is the index of stat
    }
    for (int i = 0; i < n; i++) {
        if (stat[i] > credit) {
            credit = stat[i];
            res = i;
        }
    }
    return res;
}