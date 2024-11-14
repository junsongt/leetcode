
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

// 3249. 统计好节点的数目
/*
现有一棵 无向 树，树中包含 n 个节点，按从 0 到 n - 1 标记。树的根节点是节点 0 。给你一个长度为 n - 1 的二维整数数组 edges，其中 edges[i] = [ai, bi] 表示树中节点 ai 与节点 bi 之间存在一条边。

如果一个节点的所有子节点为根的
子树
 包含的节点数相同，则认为该节点是一个 好节点。

返回给定树中 好节点 的数量。

子树 指的是一个节点以及它所有后代节点构成的一棵树。
*/

int countGoodNodes(vector<vector<int>>& edges) {
    int res = 0;
    int n = edges.size();
    // create adjacency list
    vector<vector<int>> adj(n + 1);  // since for tree: #vertices = #edges + 1
    for (auto edge : edges) {
        int n1 = edge[0];
        int n2 = edge[1];
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    // lambda helper to return the size of the subtree of node, and its parent par
    // use std::function container to store the lambda function
    // syntax: std::function<void(int, int)> means a function takes (int, int) and returns void
    std::function<int(int, int)> dfs = [&](int curr, int par) -> int {
        bool good = true;
        int sub_size_ref = 0;
        int total_size = 0;

        for (int sub : adj[curr]) {
            if (sub != par) {
                int sub_size = dfs(sub, curr);  // return the size of subtree
                if (sub_size_ref == 0) {
                    sub_size_ref = sub_size;
                    // if reference of subtree size has not yet been set up, then set up
                } else if (sub_size != sub_size_ref) {
                    good = false;
                    // if subtree size not equal then violate the rule of "good"
                }
                // accumulate the total size of the tree of root: curr
                total_size += sub_size;
            }
        }
        if (good) {
            res++;  // if curr is a good node, then update res
        }
        return total_size + 1;  // total tree size has to include the root: curr
    };

    dfs(0, -1);
    return res;
}