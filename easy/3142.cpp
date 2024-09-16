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

// 3142. 判断矩阵是否满足条件

/*
给你一个大小为 m x n 的二维矩阵 grid 。你需要判断每一个格子 grid[i][j] 是否满足：

如果它下面的格子存在，那么它需要等于它下面的格子，也就是 grid[i][j] == grid[i + 1][j] 。
如果它右边的格子存在，那么它需要不等于它右边的格子，也就是 grid[i][j] != grid[i][j + 1] 。
如果 所有 格子都满足以上条件，那么返回 true ，否则返回 false 。
*/

bool satisfiesConditions(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        if (i < grid.size() - 1) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (j < grid[i].size() - 1) {
                    if (grid[i][j] != grid[i + 1][j] || grid[i][j] == grid[i][j + 1]) {
                        return false;
                    }
                } else {
                    if (grid[i][j] != grid[i + 1][j]) {
                        return false;
                    }
                }
            }
        } else {
            for (int j = 0; j < grid[i].size(); j++) {
                if (j < grid[i].size() - 1) {
                    if (grid[i][j] == grid[i][j + 1]) {
                        return false;
                    }
                } else {
                    return true;
                }
            }
        }
    }
    return true;
}