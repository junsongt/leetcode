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

// 1436. 旅行终点站

/*
给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。
*/

string destCity(vector<vector<string>>& paths) {
    // this counts the out flow of each node, as destination has 0 out flow
    unordered_map<string, int> outs;
    string res;
    for (auto p : paths) {
        string start = p[0];
        string end = p[1];
        auto it = outs.find(start);
        // start node has out flow, record it, but also record the end node's out flow = 0
        if (it == outs.end()) {
            outs[start] = 1;
        } else {
            (it->second)++;
        }
        it = outs.find(end);
        if (it == outs.end()) {
            outs[end] = 0;
        }
    }
    int n = outs.size();
    for (auto node : outs) {
        if (node.second == 0) {
            res = node.first;
        }
    }
    return res;
}