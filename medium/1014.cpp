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

// 1014. 最佳观光组合
/*
给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。

一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去 它们两者之间的距离。

返回一对观光景点能取得的最高分。
*/

int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int res = 0;
    // max{values[i]+values[j]+i-j} = max{(values[i]+i) + (values[j]-j)}
    int temp = values[0] + 0;  // temp = max{values[i]+i, forall i < j} for each fixed j

    for (int j = 1; j < n; j++) {
        res = max(res, temp + values[j] - j);
        temp = max(temp, values[j] + j);
    }
    return res;

    // int n = values.size();
    // int res = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i+1; j < n; j++) {
    //         res = max(res, values[i] + values[j] + i - j);
    //     }
    // }
    // return res;
}
