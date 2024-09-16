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

// 70. 爬楼梯
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/

int climbStairs(int n) {
    // if (n == 1) {
    //     return 1;
    // }
    // if (n == 2) {
    //     return 2;
    // } else {
    //     // had to use tail recursion; o/w timeout from stack
    //     int x_n_2 = 1;
    //     int x_n_1 = 2;
    //     while (n > 2) {
    //         if (n - 2 == 1) {
    //             x_n_2 = x_n_1 + x_n_2;
    //             return x_n_2;
    //         } else {
    //             x_n_2 = x_n_1 + x_n_2;
    //             x_n_1 = x_n_2 + x_n_1;
    //             // return x_n_1
    //         }
    //         n = n - 2;
    //     }
    //     return x_n_1;
    // }
    int prev = 1;
    int curr = 1;
    while (n > 1) {
        int temp = prev + curr;
        prev = curr;
        curr = temp;
        n--;
    }
    return curr;
}