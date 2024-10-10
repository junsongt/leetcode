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

// 2073. 买票需要的时间

/*
有 n 个人前来排队买票，其中第 0 人站在队伍 最前方 ，第 (n - 1) 人站在队伍 最后方 。

给你一个下标从 0 开始的整数数组 tickets ，数组长度为 n ，其中第 i 人想要购买的票数为 tickets[i] 。

每个人买票都需要用掉 恰好 1 秒 。一个人 一次只能买一张票 ，如果需要购买更多票，他必须走到  队尾 重新排队（瞬间 发生，不计时间）。如果一个人没有剩下需要买的票，那他将会 离开 队伍。

返回位于位置 k（下标从 0 开始）的人完成买票需要的时间（以秒为单位）。
*/

int timeRequiredToBuy(vector<int>& tickets, int k) {
    // // method 1: append sequence
    // // (5111)(4000)(3000)(2000)(1000)(0...)
    // // (232)(121)(010)
    // int n = tickets.size();
    // int time = 0;
    // while (tickets[k] > 0) {
    //     for (int i = 0; i < n; i++) {
    //         if (tickets[i] != 0) {
    //             time++;
    //             tickets[i]--;
    //         }
    //         if (tickets[k] == 0) {
    //             break;
    //         }
    //     }
    // }
    // return time;

    // method 2: using queue
    int n = tickets.size();
    int time = 0;
    queue<int> line;  // queue of index

    for (int i = 0; i < n; i++) {
        line.push(i);
    }
    while (tickets[k] != 0) {
        tickets[line.front()]--;
        if (tickets[line.front()] != 0) {
            line.push(line.front());
            line.pop();
        } else {
            line.pop();
        }
        time++;
    }
    return time;
}