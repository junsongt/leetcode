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

// 2187. 完成旅途的最少时间
/*
给你一个数组 time ，其中 time[i] 表示第 i 辆公交车完成 一趟旅途 所需要花费的时间。

每辆公交车可以 连续 完成多趟旅途，也就是说，一辆公交车当前旅途完成后，可以 立马开始 下一趟旅途。每辆公交车 独立 运行，也就是说可以同时有多辆公交车在运行且互不影响。

给你一个整数 totalTrips ，表示所有公交车 总共 需要完成的旅途数目。请你返回完成 至少 totalTrips 趟旅途需要花费的 最少 时间。
*/

long long minimumTime(vector<int>& time, int totalTrips) {
    // this lambda function serves to check if this time length is long enough for the overall trips of all buses to satisfy the totaltrip condition
    auto not_enough = [&](long long t) -> bool {
        long long sum = 0;
        for (int x : time) {
            sum += t / x;
        }
        return (sum < totalTrips);
    };
    /*
    We will use binary search to get the exact time
    But the usual lower & upper bound is [1, totaltrips*max(time)], which is a bit broad, we have have better lower bound for search:
    Let c be the overall trips of all buses for certain time t, and x_i \in time, we have:
    \sum_{i=1}^n floor(t / x_i) = c
    ==> \sum_{i=1}^n ((t/x_i) - frac(t/x_i))  = c
    ==> (\sum_{i=1}^n (t/x_i)) - (\sum_{i=1}^n frac(t/x_i)) = c <= \sum_{i=1}^n (t/x_i)
    ==> t * \sum_{i=1}^n (1/x_i) >= c
    ==> t >= c / \sum_{i=1}^n (1/x_i)
    ==> t >= ceil(c / \sum_{i=1}^n (1/x_i)) since t is integer
    */

    // getting new lower bound
    double inv_sum = 0.0;
    int max_time = 0;
    for (int x : time) {
        inv_sum += 1.0 / x;
        max_time = max(max_time, x);
    }
    long long l = ceil((totalTrips * 1.0) / inv_sum);  // new lower bound
    long long r = (long long)totalTrips * max_time;    // old upper bound

    while (l < r) {
        long long mid = l + (r - l) / 2;
        // if time not enough, increase lower bound > mid
        if (not_enough(mid)) {
            l = mid + 1;
        }
        // if too far, reduce upper bound to mid
        else {
            r = mid;
        }
    }
    return r;
}