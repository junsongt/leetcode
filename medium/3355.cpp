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

// 3355. 零数组变换 I
/*
给定一个长度为 n 的整数数组 nums 和一个二维数组 queries，其中 queries[i] = [li, ri]。

对于每个查询 queries[i]：

在 nums 的下标范围 [li, ri] 内选择一个下标 子集。
将选中的每个下标对应的元素值减 1。
零数组 是指所有元素都等于 0 的数组。

如果在按顺序处理所有查询后，可以将 nums 转换为 零数组 ，则返回 true，否则返回 false。
*/

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> diff(n);
    diff[0] = nums[0];
    for (int i = 1; i < n; i++) {
        diff[i] = nums[i] - nums[i - 1];
    }
    int m = queries.size();
    for (int i = 0; i < m; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        diff[l]--;
        if (r + 1 <= n - 1) {
            diff[r + 1]++;
        }
    }
    nums[0] = diff[0];
    bool stop = (nums[0] > 0);
    int i = 1;
    while (i < diff.size() && !stop) {
        nums[i] = nums[i - 1] + diff[i];
        if (nums[i] > 0) {
            stop = true;
        }
        i++;
    }
    return !stop;
}
