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

// 3259. 超级饮料的最大强化能量
/*
来自未来的体育科学家给你两个整数数组 energyDrinkA 和 energyDrinkB，数组长度都等于 n。这两个数组分别代表 A、B 两种不同能量饮料每小时所能提供的强化能量。

你需要每小时饮用一种能量饮料来 最大化 你的总强化能量。然而，如果从一种能量饮料切换到另一种，你需要等待一小时来梳理身体的能量体系（在那个小时里你将不会获得任何强化能量）。

返回在接下来的 n 小时内你能获得的 最大 总强化能量。

注意 你可以选择从饮用任意一种能量饮料开始。
*/

long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
    long long E_A = 0;
    long long E_B = 0;
    int n = energyDrinkA.size();
    long long res = 0;
    /*
    E_A(i) = E_A(i-1) + A_i, if at time (i-1), on A;
           = E_B(i-1),       if at time (i-1), on B;

    E_B(i) = E_A(i-1),       if at time (i-1), on A;
           = E_B(i-1) + B_i, if at time (i-1), on B;
    */
    for (int i = 0; i < n; i++) {
        long long prevA = E_A;
        long long prevB = E_B;
        E_A = max(prevA + energyDrinkA[i], prevB);
        E_B = max(prevA, prevB + energyDrinkB[i]);
    }
    res = max(E_A, E_B);
    return res;
}