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

// 88. 合并两个有序数组
/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp;
    // parser for nums1
    int i = 0;
    // parser for nums2
    int j = 0;
    while (j < n && i < m) {
        if (nums1[i] <= nums2[j]) {
            temp.push_back(nums1[i]);
            i++;
        } else {
            temp.push_back(nums2[j]);
            j++;
        }
    }
    if (j < n) {
        for (int k = j; k < n; k++) {
            temp.push_back(nums2[k]);
        }
    } else if (i < m) {
        for (int k = i; k < m; k++) {
            temp.push_back(nums1[k]);
        }
    }
    nums1 = temp;
}