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

// 134. 加油站
/*
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    vector<int> net_gas_left(n);  // this records the net gas left on arriving gas station i from station i-1 (note -1 = n-1)
    int net_sum = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + n - 1) % n;
        net_gas_left[i] = gas[j] - cost[j];
        net_sum += net_gas_left[i];
    }
    // the net gas < 0, then it's impossible to complete the circle
    if (net_sum < 0) {
        return -1;
    }

    /*
    Now all we need to do is to find a starting point in net_gas_left such that the cumulative sum is always >= 0.
    key obseravtion is:
    (1). we should always start at a non-negative number
    (2). if chosen a starting point: "*"" (* >=0), denote the cumulative sum as sum1, and suddenly sum1 < 0, which only happens when we hit a negative. But during parsing, we could also encounter other non-negative numbers: "+". Suppose we choose "+" as alternative starting point, then its cumulative sum as sum2.
    As shown below, sum1 is outer bracket and sum2 is the inner

    (* - - (+ -))

    then we must have:
    sum1 - sum2 = (*) + (-) + (-) >= 0, since otherwise, the pasring would stop before "+", so thus sum2 <= sum1 < 0. In short, we will skip all non-negative points during parsing until it stops. If it stops before n steps, then start to search a new starting point(>=0)

    */
    // set double pointers, pasring the net_gas_left only once
    int start = 0;
    int l = start;
    while (l < n) {
        // search a starting point
        while (net_gas_left[l] < 0) {
            l++;
        }
        start = l;
        int acc = 0;  // begin calculating cumulative sum
        while (acc >= 0 && l < n) {
            acc += net_gas_left[l];
            l++;
        }
        // if stops before n steps(didn't finish the circle), set new start
        if (l < n) {
            start = l;
        }
    }
    // recover the actual "start" by moving one step back and modulo overflow handling
    return (start - 1 + n) % n;

    // // below exceed the time limit!
    // for (int i = 0; i < n; i++) {
    //     int j = i;
    //     int curr = net_gas_left[j%n];
    //     if (curr >= 0) {
    //         int accum = 0;
    //         while (accum >= 0 && (j-i) < n) {
    //             accum += net_gas_left[j%n];
    //             j++;
    //         }
    //         if (j - i == n) {
    //             start = (i-1+n)%n;
    //         }
    //     }
    // }
    // return start;
}