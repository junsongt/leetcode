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

// 661. 图片平滑器
/*
图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。

每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。

如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。

给你一个表示图像灰度的 n x m 整数矩阵 img ，返回对图像的每个单元格平滑处理后的图像 。
*/

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int n = img.size();
    int m = img[0].size();
    vector<vector<int>> res = img;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int count = 0;
            int sum = 0;
            if (i - 1 >= 0 && j - 1 >= 0) {
                sum += img[i - 1][j - 1];
                count++;
            }  // ul
            if (i - 1 >= 0) {
                sum += img[i - 1][j];
                count++;
            }  // u
            if (i - 1 >= 0 && j + 1 <= m - 1) {
                sum += img[i - 1][j + 1];
                count++;
            }  // ur

            if (j - 1 >= 0) {
                sum += img[i][j - 1];
                count++;
            }  // l
            if (j + 1 <= m - 1) {
                sum += img[i][j + 1];
                count++;
            }  // r

            if (i + 1 <= n - 1 && j - 1 >= 0) {
                sum += img[i + 1][j - 1];
                count++;
            }  // dl
            if (i + 1 <= n - 1) {
                sum += img[i + 1][j];
                count++;
            }  // d
            if (i + 1 <= n - 1 && j + 1 <= m - 1) {
                sum += img[i + 1][j + 1];
                count++;
            }  // dr

            res[i][j] = (sum + img[i][j]) / (count + 1);
        }
    }
    return res;
}