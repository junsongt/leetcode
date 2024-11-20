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

// 3240. 最少翻转次数使二进制矩阵回文 II
/*
给你一个 m x n 的二进制矩阵 grid 。

如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 回文 的。

你可以将 grid 中任意格子的值 翻转 ，也就是将格子里的值从 0 变成 1 ，或者从 1 变成 0 。

请你返回 最少 翻转次数，使得矩阵中 所有 行和列都是 回文的 ，且矩阵中 1 的数目可以被 4 整除 。
*/

int minFlips(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;

    for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int ul = grid[i][j];
            int ur = grid[i][n - 1 - j];
            int dl = grid[m - 1 - i][j];
            int dr = grid[m - 1 - i][n - 1 - j];
            if (ul != ur || ur != dl || dl != dr) {
                if (ul + ur + dl + dr == 2) {
                    res += 2;
                }
                if ((ul + ur + dl + dr) % 2 == 1) {
                    res++;
                }
            }
        }
    }

    int count = 0;  // count of pair of (1,1)
    // if count is odd, then either (0,0)->(1,1) or (1,1)->(0,0) will make the count even, thus # of 1s = 2*count = 0 (mod 4)
    int diff = 0;  // count of (0,1) or (1,0)
    if (m % 2 != 0) {
        for (int k = 0; k < n / 2; k++) {
            // if (0, 1), then change them to (0, 0)
            if (grid[m / 2][k] != grid[m / 2][n - 1 - k]) {
                diff++;
            } else {
                if (grid[m / 2][k] == 1) {
                    count++;
                }
            }
        }
    }
    if (n % 2 != 0) {
        for (int k = 0; k < m / 2; k++) {
            if (grid[k][n / 2] != grid[m - 1 - k][n / 2]) {
                diff++;
            } else {
                if (grid[k][n / 2] == 1) {
                    count++;
                }
            }
        }
    }

    // center has to be 0. otherwise number of 1s would be odd
    if (m % 2 != 0 && n % 2 != 0) {
        res += grid[m / 2][n / 2];
    }

    // if count even & diff = 0, then we are done
    // if count even & diff > 0, then make all (0,1)->(0,0)
    if (count % 2 == 0 && diff > 0) {
        res += diff;
    }
    // if count odd & diff > 0, then make one of (0,1)->(1,1) to make count even, and the rest (0,1)->(0,0) will still make count even
    if (count % 2 != 0 && diff > 0) {
        res += diff;
    }
    // if count odd & diff == 0, then (0,0)->(1,1) or (1,1)->(0,0) will make count even
    if (count % 2 != 0 && diff == 0) {
        res += 2;
    }
    return res;
}