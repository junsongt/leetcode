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

// 2359. 找到离给定两个节点最近的节点
/*
给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，每个节点 至多 有一条出边。

有向图用大小为 n 下标从 0 开始的数组 edges 表示，表示节点 i 有一条有向边指向 edges[i] 。如果节点 i 没有出边，那么 edges[i] == -1 。

同时给你两个节点 node1 和 node2 。

请你返回一个从 node1 和 node2 都能到达节点的编号，使节点 node1 和节点 node2 到这个节点的距离 较大值最小化。如果有多个答案，请返回 最小 的节点编号。如果答案不存在，返回 -1 。

注意 edges 可能包含环。
*/

// vector<int> parse(int start_node, vector<int>& edges) {
//     int n = edges.size();
//     vector<int> dist_from_start(n, -1);
//     vector<bool> visited(n, false);
//     visited[start_node] = true;
//     dist_from_start[start_node] = 0;
//     int destination = edges[start_node];
//     int dist = 0;
//     while (destination != -1 && visited[destination] == false) {
//         dist++;
//         dist_from_start[destination] = dist;
//         visited[destination] = true;
//         destination = edges[destination];
//     }
//     return dist_from_start;
// }

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist_from_n1(n, -1);
    vector<int> dist_from_n2(n, -1);
    auto parse = [n, &edges](int start_node, vector<int>& dist_from_start) -> void {
        vector<bool> visited(n, false);
        visited[start_node] = true;
        dist_from_start[start_node] = 0;
        int destination = edges[start_node];
        int dist = 0;
        while (destination != -1 && visited[destination] == false) {
            dist++;
            dist_from_start[destination] = dist;
            visited[destination] = true;
            destination = edges[destination];
        }
    };
    parse(node1, dist_from_n1);
    parse(node2, dist_from_n2);
    // vector<int> dist_from_n1 = parse(node1, edges);
    // vector<int> dist_from_n2 = parse(node2, edges);

    int min_common_dist = n + 1;
    int minimizer = 0;
    for (int node = 0; node < n; node++) {
        int dist1 = dist_from_n1[node];
        int dist2 = dist_from_n2[node];
        if (dist1 >= 0 && dist2 >= 0) {
            if (max(dist1, dist2) < min_common_dist) {
                min_common_dist = max(dist1, dist2);
                minimizer = node;
            }
        }
    }
    if (min_common_dist == n + 1) {
        return -1;
    } else {
        return minimizer;
    }
}