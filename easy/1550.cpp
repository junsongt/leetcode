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

// 1550. 存在连续三个奇数的数组
/*
给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。

示例 1：

输入：arr = [2,6,4,1]
输出：false
解释：不存在连续三个元素都是奇数的情况。
示例 2：

输入：arr = [1,2,34,3,4,5,7,23,12]
输出：true
解释：存在连续三个元素都是奇数的情况，即 [5,7,23] 。
*/
bool threeConsecutiveOdds(vector<int>& arr) {
    int l = 0;
    int r = l;
    int cnt = 0;
    while (l < arr.size() && cnt < 3) {
        while (r < arr.size() && arr[r] % 2 != 0) {
            r++;
        }
        cnt = r - l;
        l = r + 1;
        r = l;
    }
    return (cnt >= 3);
}
