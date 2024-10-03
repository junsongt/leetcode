#include <time.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

// 1227. 飞机座位分配概率
/*
有 n 位乘客即将登机，飞机正好有 n 个座位。第一位乘客的票丢了，他随便选了一个座位坐下。

剩下的乘客将会：

如果他们自己的座位还空着，就坐到自己的座位上，

当他们自己的座位被占用时，随机选择其他座位
第 n 位乘客坐在自己的座位上的概率是多少？
*/

double nthPersonGetsNthSeat(int n) {
    // let f(n) = P(n-th man in his seat for n-man case)
    /*
    base case: f(1) = 1; f(2) = 2;
    claim for all n >= 2, f(n) = 1/2
    Proof: suppose that for (n-1) case, there are total N number of cases, among which, N/2 cases are that (n-1)th man in his seat;
    Then, if we add one more seat at the end, then all cases for the (n-1)-man case are considered that n-th man is in his seat since no one takes the n-th seat when we have (n-1)-man case. But for n-man case, we have addtional N possibilities when anyone else except the n-th man takes his seat, so the total number of cases for n-man is 2N, so the f(n) = N/2N = 1/2
    */
    return (n == 1) ? 1 : 0.5;
}
