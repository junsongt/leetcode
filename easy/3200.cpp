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

// 3200. 三角形的最大高度
/*
给你两个整数 red 和 blue，分别表示红色球和蓝色球的数量。你需要使用这些球来组成一个三角形，满足第 1 行有 1 个球，第 2 行有 2 个球，第 3 行有 3 个球，依此类推。

每一行的球必须是 相同 颜色，且相邻行的颜色必须 不同。

返回可以实现的三角形的 最大 高度。
*/

int triangle(int first, int second) {
    int level = 1;
    int curr = first;
    while (curr >= level) {
        if (level % 2 != 0) {
            first -= level;
            curr = second;
        } else {
            second -= level;
            curr = first;
        }
        level++;
    }
    return level - 1;
}

int maxHeightOfTriangle(int red, int blue) {
    return max(triangle(red, blue), triangle(blue, red));
}