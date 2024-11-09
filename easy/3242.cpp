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

// 3242. 设计相邻元素求和服务
/*
给你一个 n x n 的二维数组 grid，它包含范围 [0, n2 - 1] 内的不重复元素。

实现 neighborSum 类：

neighborSum(int [][]grid) 初始化对象。
int adjacentSum(int value) 返回在 grid 中与 value 相邻的元素之和，相邻指的是与 value 在上、左、右或下的元素。
int diagonalSum(int value) 返回在 grid 中与 value 对角线相邻的元素之和，对角线相邻指的是与 value 在左上、右上、左下或右下的元素。
*/

class NeighborSum {
   public:
    vector<vector<int>> grid;
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }
    vector<int> search(int value) {
        int n = this->grid.size();
        int i = 0;
        int j = 0;
        bool found = false;
        while (i < n && !found) {
            j = 0;
            while (j < n && !found) {
                if (this->grid[i][j] == value) {
                    found = true;
                } else {
                    j++;
                }
            }
            if (!found) {
                i++;
            }
        }
        return vector<int>{i, j};
    }

    int adjacentSum(int value) {
        int n = this->grid.size();
        vector<int> coord = search(value);
        int i = coord[0];
        int j = coord[1];

        int up = (i - 1 < 0) ? 0 : this->grid[i - 1][j];
        int down = (i + 1 > n - 1) ? 0 : this->grid[i + 1][j];
        int left = (j - 1 < 0) ? 0 : this->grid[i][j - 1];
        int right = (j + 1 > n - 1) ? 0 : this->grid[i][j + 1];
        return up + down + left + right;
    }

    int diagonalSum(int value) {
        int n = this->grid.size();
        vector<int> coord = search(value);
        int i = coord[0];
        int j = coord[1];
        int ul = (i - 1 < 0 || j - 1 < 0) ? 0 : this->grid[i - 1][j - 1];
        int ur = (i - 1 < 0 || j + 1 > n - 1) ? 0 : this->grid[i - 1][j + 1];
        int dl = (i + 1 > n - 1 || j - 1 < 0) ? 0 : this->grid[i + 1][j - 1];
        int dr = (i + 1 > n - 1 || j + 1 > n - 1) ? 0 : this->grid[i + 1][j + 1];
        return ul + ur + dl + dr;
    }
};

int main() {
    // Your NeighborSum object will be instantiated and called as such:
    vector<vector<int>> grid = {
        {1, 2, 0, 3},
        {4, 7, 15, 6},
        {8, 9, 10, 11},
        {12, 13, 14, 5}};
    NeighborSum* obj = new NeighborSum(grid);
    int param_1 = obj->adjacentSum(3);
    int param_2 = obj->diagonalSum(0);
    cout << param_1 << endl;
    cout << param_2 << endl;
}