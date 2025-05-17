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

// 75. 颜色分类
/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库内置的 sort 函数的情况下解决这个问题。
*/

void sortColors(vector<int>& nums) {
    // // method 1
    // int freq[3];
    // for (int c : nums) {
    //     freq[c]++;
    // }
    // for (int i = 0; i < nums.size(); i++) {
    //     if (i < freq[0]) {
    //         nums[i] = 0;
    //     }
    //     if (freq[0] <= i && i < freq[0] + freq[1]) {
    //         nums[i] = 1;
    //     }
    //     if (i >= freq[0] + freq[1]) {
    //         nums[i] = 2;
    //     }
    // }
    // method 2: 2 pointers, one for swapping 0 and one for 1
    int n = nums.size();
    auto swap = [](int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    };
    int ptr0 = 0;
    int ptr1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            swap(nums[ptr0], nums[i]);
            if (ptr0 < ptr1) {
                swap(nums[i], nums[ptr1]);
            }
            ptr0++;
            ptr1++;
        } else if (nums[i] == 1) {
            swap(nums[ptr1], nums[i]);
            ptr1++;
        }
    }
}
