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

// 62. 不同路径
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
*/

int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
            }
        }
    }

    return grid[m - 1][n - 1];

    // runtime error: signed integer overflow: 6761440164390912000 * 30 cannot be represented in type 'long long'
    // int A = max(m-1,n-1);
    // int a = min(m-1,n-1);
    // long long fac = 1;
    // long long temp = 1;

    // for (int i = 1; i <= a; i++) {
    //     fac *= i;
    //     temp *= (i+A);
    // }
    // return temp / fac;

    // runtime error: signed integer overflow: 6761440164390912000 * 30 cannot be represented in type 'long long'
    // // calculate factorial
    // long long int fac_m = 1;
    // long long int fac_n = 1;
    // long long int fac = 1;
    // for (int i = 1; i <= m+n-2; i++) {
    //     if (i <= m-1) {
    //         fac_m *= i;
    //     }
    //     if (i <= n-1) {
    //         fac_n *= i;
    //     }
    //     fac *= i;

    // }
    // return fac / (fac_m * fac_n);
}