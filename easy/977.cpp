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

// 977. 有序数组的平方
/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
*/

// time complexity: O(n), space: O(n)
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int front = 0;
    int back = n - 1;
    stack<int> temp;
    while (front <= back) {
        if (abs(nums[front]) < abs(nums[back])) {
            temp.push(nums[back] * nums[back]);
            back--;
        } else {
            temp.push(nums[front] * nums[front]);
            front++;
        }
    }
    int i = 0;
    while (!temp.empty()) {
        nums[i] = temp.top();
        temp.pop();
        i++;
    }
    return nums;
}

// // time complexity: O(n), space: O(1)
// vector<int> sortedSquares(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> res;
//     int left = 0;
//     int right = 0;
//     while (left < n && nums[left] < 0) {
//         left++;
//     }
//     if (left == 0) {
//         for (int x : nums) {
//             res.push_back(x * x);
//         }
//     } else if (left == n) {
//         for (int i = n - 1; i >= 0; i--) {
//             res.push_back(nums[i] * nums[i]);
//         }
//     } else {
//         right = left;
//         left--;
//         while (left >= 0 || right <= n - 1) {
//             if (left >= 0 && right <= n - 1 && abs(nums[left]) < abs(nums[right])) {
//                 res.push_back(nums[left] * nums[left]);
//                 left--;
//             } else if (left >= 0 && right <= n - 1 && abs(nums[left]) >= abs(nums[right])) {
//                 res.push_back(nums[right] * nums[right]);
//                 right++;
//             } else if (left < 0 && right <= n - 1) {
//                 res.push_back(nums[right] * nums[right]);
//                 right++;
//             } else {
//                 res.push_back(nums[left] * nums[left]);
//                 left--;
//             }
//         }
//     }
//     return res;
// }