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

// 2860. 让所有学生保持开心的分组方法数
/*
给你一个下标从 0 开始、长度为 n 的整数数组 nums ，其中 n 是班级中学生的总数。班主任希望能够在让所有学生保持开心的情况下选出一组学生：

如果能够满足下述两个条件之一，则认为第 i 位学生将会保持开心：

这位学生被选中，并且被选中的学生人数 严格大于 nums[i] 。
这位学生没有被选中，并且被选中的学生人数 严格小于 nums[i] 。
返回能够满足让所有学生保持开心的分组方法的数目。
*/

/*
some facts:
(1) if Xi is selected, then for all Xj <= Xi are selected;
(2) if Xi is NOT selected, then for all Xj >= Xi are NOT selected;

Sort the array first. Assume nums is an sorted array.
Basically we will find the indices such that nums[i] < i and nums[i+1] > i (fopr those who are on the y = x line do not count, where y is selected set size and x is indices(1-based))
Be careful about the boundary check:
if index is at the end, don't check the next one;
if index is 0, then just check if nums[0] > 0 since at this case, selected set size is 0


*/

int countWays(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    sort(nums.begin(), nums.end());
    for (int i = n; i >= 0; i--) {
        if (i == n && nums[i - 1] < i) {
            count++;
        }
        if (i > 0 && i < n && nums[i - 1] < i && nums[i] > i) {
            count++;
        }
        if (i == 0 && nums[i] > i) {
            count++;
        }
    }

    // while (selected >= 0) {
    //     int i = 0;
    //     while (i < selected && nums[i] < selected) {
    //         i++;
    //     }
    //     if (i == selected) {
    //         count++;
    //         selected--;
    //     }
    //     else {
    //         selected = i;
    //     }

    // }
    return count;
}