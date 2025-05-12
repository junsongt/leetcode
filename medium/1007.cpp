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

// 1007. 行相等的最少多米诺旋转
/*
在一排多米诺骨牌中，tops[i] 和 bottoms[i] 分别代表第 i 个多米诺骨牌的上半部分和下半部分。（一个多米诺是两个从 1 到 6 的数字同列平铺形成的 —— 该平铺的每一半上都有一个数字。）

我们可以旋转第 i 张多米诺，使得 tops[i] 和 bottoms[i] 的值交换。

返回能使 tops 中所有值或者 bottoms 中所有值都相同的最小旋转次数。

如果无法做到，返回 -1.
*/
int min_for_ref(int ref, vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size();
    int flip_for_top = 0;     // # of flips to make all top = ref
    int flip_for_bottom = 0;  // # of flips to make all bottom = ref
    for (int i = 0; i < n; i++) {
        int t = tops[i];
        int b = bottoms[i];
        if (t != ref && b != ref) {
            return -1;  // if there is a card whose top and bottom are not ref, then impossible to flip
        }
        if (t == ref && b != ref) {
            flip_for_bottom++;
        }
        if (t != ref && b == ref) {
            flip_for_top++;
        }
    }
    return min(flip_for_top, flip_for_bottom);  // wish to min over two possible flip modes
}

int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int res_top = min_for_ref(tops[0], tops, bottoms);
    int res_bottom = min_for_ref(bottoms[0], tops, bottoms);
    if (res_top < 0 || res_bottom < 0) {
        return max(res_top, res_bottom);  // if there is one flip mode gives -1, then take the positive one
    } else {
        return min(res_top, res_bottom);  // if both flips are possible, take min
    }
}
