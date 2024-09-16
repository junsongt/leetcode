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

// 35. 搜索插入位置
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/

int searchInsert(vector<int>& nums, int target) {
    int idx = -1;
    int L = 0;
    int R = nums.size() - 1;
    int mid;
    while (L <= R) {
        mid = L + (R - L) / 2;
        if (nums[mid] < target) {
            L = mid + 1;
        } else if (nums[mid] > target) {
            R = mid - 1;
        } else {
            idx = mid;
            return idx;
        }
    }
    if (target > nums[mid]) {
        idx = mid + 1;
    } else {
        idx = mid;
    }
    return idx;
}