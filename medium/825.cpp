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

// 825. 适龄的朋友

/*
在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。

如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：

ages[y] <= 0.5 * ages[x] + 7
ages[y] > ages[x]
ages[y] > 100 && ages[x] < 100
否则，x 将会向 y 发送一条好友请求。

注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。

返回在该社交媒体网站上产生的好友请求总数。

*/

int numFriendRequests(vector<int>& ages) {
    int n = ages.size();
    sort(ages.begin(), ages.end());
    // send-request critierion from (x -> y) is:
    // (0.5*x+7 < y <= x) & (y <= 100 or x >= 100)
    // also 0.5*x+7 < x ===> x > 14

    int res = 0;
    int l = n - 1;
    int repeat = 0;
    int prev = ages[n - 1];
    for (int r = n - 1; r > 0; r--) {
        if (l == r) {
            l = r - 1;
        }
        while (l >= 0 && ages[l] > 0.5 * ages[r] + 7) {
            l--;
        }
        res += r - (l + 1);

        // if find some one same age, repeat <- repeat+1
        if (r < n - 1 && ages[r] == prev && ages[r] > 14) {
            repeat++;
        }
        // if not, then for the same age group, its size = repeat+1, and should add additional [(repeat+1) choose 2] requests
        else if (r < n - 1 && ages[r] != prev && ages[r] > 14) {
            res += ((repeat + 1) * repeat) / 2;
            repeat = 0;
        }
        prev = ages[r];
    }
    if (ages[0] == prev && ages[0] > 14) {
        repeat++;
    }
    res += ((repeat + 1) * repeat) / 2;

    return res;
}