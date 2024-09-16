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

// 3127. 构造相同颜色的正方形

/*
给你一个二维 3 x 3 的矩阵 grid ，每个格子都是一个字符，要么是 'B' ，要么是 'W' 。字符 'W' 表示白色，字符 'B' 表示黑色。

你的任务是改变 至多一个 格子的颜色，使得矩阵中存在一个 2 x 2 颜色完全相同的正方形。

如果可以得到一个相同颜色的 2 x 2 正方形，那么返回 true ，否则返回 false 。
*/

bool canMakeSquare(vector<vector<char>>& grid) {
    int r = 0;  // row parser
    while (r <= 1) {
        int c = 0;  // column parser
        while (c <= 1) {
            if ((grid[r][c] == grid[r][c + 1] && grid[r][c] == grid[r + 1][c]) ||
                (grid[r][c + 1] == grid[r + 1][c + 1] && grid[r][c + 1] == grid[r][c]) ||
                (grid[r + 1][c] == grid[r][c] && grid[r + 1][c] == grid[r + 1][c + 1]) ||
                (grid[r + 1][c + 1] == grid[r][c + 1] && grid[r + 1][c + 1] == grid[r + 1][c])) {
                return true;
            } else {
                c++;
            }
        }
        r++;
    }
    return false;
}