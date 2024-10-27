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

// 684. 冗余连接
/*
树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
*/

/*
IDEA: using the implementaion of "disjoint set" structure!
initialization: (-1, -1, -1, ..., -1)
method: find(node) { root parent node }
        union(node1, node2) { find(node2) = node1 } (set node2's root to node1)


WARNING:
index <--> actual node number - 1
node 0 in parents means actual node 1
*/

// find the root parent of given node
int find_root(vector<int>& parents, int node) {
    if (parents[node] < 0) {
        return node;
    } else {
        return find_root(parents, parents[node]);
    }
}
// merge the root parent of node2 onto node1
void merge(vector<int>& parents, int node1, int node2) {
    parents[find_root(parents, node2)] = node1;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parents(n);  // parents[i] is the direct parent of node i, if -1, then node i is parent and has no parent
    vector<int> res;

    for (int i = 0; i < n; i++) {
        parents[i] = -1;
    }
    for (auto edge : edges) {
        int node1 = edge[0] - 1;
        int node2 = edge[1] - 1;
        // if two nodes don't have common root, then they are in different components, union them
        if (find_root(parents, node1) != find_root(parents, node2)) {
            merge(parents, node1, node2);
        } else {
            res = edge;
        }
    }
    return res;
}