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

// 3239. 最少翻转次数使二进制矩阵回文 I
/*
给你一个 m x n 的二进制矩阵 grid 。

如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 回文 的。

你可以将 grid 中任意格子的值 翻转 ，也就是将格子里的值从 0 变成 1 ，或者从 1 变成 0 。

请你返回 最少 翻转次数，使得矩阵 要么 所有行是 回文的 ，要么所有列是 回文的 。
*/

int minFlips(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int byrow = 0;
    int bycol = 0;

    for (int i = 0; i < m; i++) {
        int j = 0;
        int k = n - 1;
        while (j <= k) {
            if (grid[i][j] != grid[i][k]) {
                byrow++;
            }
            j++;
            k--;
        }
    }

    for (int j = 0; j < n; j++) {
        int i = 0;
        int k = m - 1;
        while (i <= k) {
            if (grid[i][j] != grid[k][j]) {
                bycol++;
            }
            i++;
            k--;
        }
    }

    return min(byrow, bycol);
}