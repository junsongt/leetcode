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

// 2332. 坐上公交的最晚时间
/*
给你一个下标从 0 开始长度为 n 的整数数组 buses ，其中 buses[i] 表示第 i 辆公交车的出发时间。同时给你一个下标从 0 开始长度为 m 的整数数组 passengers ，其中 passengers[j] 表示第 j 位乘客的到达时间。所有公交车出发的时间互不相同，所有乘客到达的时间也互不相同。

给你一个整数 capacity ，表示每辆公交车 最多 能容纳的乘客数目。

每位乘客都会搭乘下一辆有座位的公交车。如果你在 y 时刻到达，公交在 x 时刻出发，满足 y <= x  且公交没有满，那么你可以搭乘这一辆公交。最早 到达的乘客优先上车。

返回你可以搭乘公交车的最晚到达公交站时间。你 不能 跟别的乘客同时刻到达。

注意：数组 buses 和 passengers 不一定是有序的。
*/

int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
    int n = buses.size();
    int m = passengers.size();
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());
    int p = 0;  // parser for pasengers
    int temp = capacity;
    int latest = 0;
    for (int b = 0; b < n; b++) {
        temp = capacity;
        // for each bus, load as passenger if they arrive before and space available
        while (p < m && passengers[p] <= buses[b] && temp > 0) {
            p++;
            temp--;
        }
    }

    p--;
    // if space left, you arrive at the last bus leaving time
    if (temp > 0) {
        latest = buses[n - 1];
    }
    // if not, try to find a gap in time from the last to push a passenger off
    else {
        latest = passengers[p];
    }
    while (latest >= 0 && p >= 0 && latest == passengers[p]) {
        p--;
        latest--;
    }
    return latest;
}