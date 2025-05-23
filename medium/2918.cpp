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

// 2918. 数组的最小相等和
/*
给你两个由正整数和 0 组成的数组 nums1 和 nums2 。

你必须将两个数组中的 所有 0 替换为 严格 正整数，并且满足两个数组中所有元素的和 相等 。

返回 最小 相等和 ，如果无法使两数组相等，则返回 -1 。


示例 1：

输入：nums1 = [3,2,0,1,0], nums2 = [6,5,0]
输出：12
解释：可以按下述方式替换数组中的 0 ：
- 用 2 和 4 替换 nums1 中的两个 0 。得到 nums1 = [3,2,2,1,4] 。
- 用 1 替换 nums2 中的一个 0 。得到 nums2 = [6,5,1] 。
两个数组的元素和相等，都等于 12 。可以证明这是可以获得的最小相等和。
示例 2：

输入：nums1 = [2,0,2,0], nums2 = [1,4]
输出：-1
解释：无法使两个数组的和相等。
*/

long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long cnt1 = 0;
    long long cnt2 = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    for (int i = 0; i < nums1.size(); i++) {
        if (nums1[i] == 0) {
            cnt1++;
        }
        sum1 += nums1[i];
    }
    for (int i = 0; i < nums2.size(); i++) {
        if (nums2[i] == 0) {
            cnt2++;
        }
        sum2 += nums2[i];
    }
    if (sum1 + cnt1 > sum2 + cnt2) {
        return (cnt2 == 0 ? -1 : sum1 + cnt1);
    }
    if (sum1 + cnt1 < sum2 + cnt2) {
        return (cnt1 == 0 ? -1 : sum2 + cnt2);
    } else {
        return sum1 + cnt1;
    }
}