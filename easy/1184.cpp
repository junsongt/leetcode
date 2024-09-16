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

// 1184. 公交站间的距离
/*
环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

环线上的公交车都可以按顺时针和逆时针的方向行驶。

返回乘客从出发点 start 到目的地 destination 之间的最短距离。
*/

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int n = distance.size();
    // clockwise distance accumulator
    int cw = 0;
    // counter-clockwise distance accumulator
    int ccw = 0;
    // total length of the loop
    int total = 0;
    // in case that start and destination are in flipped positions
    int s = min(start, destination);
    int d = max(start, destination);
    for (int i = 0; i < n; i++) {
        if (s <= i && i < d) {
            cw += distance[i];
        }
        total += distance[i];
    }
    // counter-clockwise distance accumulator is the complement
    ccw = total - cw;

    return min(cw, ccw);
}