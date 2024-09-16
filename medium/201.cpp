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

// 201. 数字范围按位与
/*
给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。
*/
// 本质是求最长公共前缀（二进制数）
// n & (n-1) 可以把最后一位变成0， 但是一旦某一位是0那么该位所有与操作都是0
// 当left < right, 存在left+1， 所以最后结果的最低位一定是0
// 然后递归依次考虑两数前几位（通过两数同时右移一位）， 直到left >= right
int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left = left >> 1;
        right = right >> 1;
        shift++;
    }
    return left << shift;
}