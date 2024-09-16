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
// 2956. 找到两个数组中的公共元素
/*
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们分别含有 n 和 m 个元素。请你计算以下两个数值：

answer1：使得 nums1[i] 在 nums2 中出现的下标 i 的数量。
answer2：使得 nums2[i] 在 nums1 中出现的下标 i 的数量。
返回 [answer1, answer2]。
*/

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> dict;
    int n = nums1.size();
    int m = nums2.size();
    int counter1 = 0;
    int counter2 = 0;
    for (int i = 0; i < n + m; i++) {
        if (i < n) {
            int key = nums1[i];
            auto it = dict.find(key);
            if (it == nullptr) {
                dict[key] = 1;
            } else {
                it->second++;
            }
        } else {
            int key = nums2[i - n];
            auto it = dict.find(key);
            // if nums2 has sth in nums1, then increment counter2
            // meanwhile it tells nums1 has sth in nums2 with its key-val being the freq, so once increment to counter1, we no longer need to increment again! Set val = 0
            if (it != nullptr) {
                counter2++;
                if (it->second != 0) {
                    counter1 += it->second;
                }
                // this is important!!!
                it->second = 0;
            }
        }
    }
    return vector<int>{counter1, counter2};
}