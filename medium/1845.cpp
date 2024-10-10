#include <time.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

// 1845. 座位预约管理系统
/*
请你设计一个管理 n 个座位预约的系统，座位编号从 1 到 n 。

请你实现 SeatManager 类：

SeatManager(int n) 初始化一个 SeatManager 对象，它管理从 1 到 n 编号的 n 个座位。所有座位初始都是可预约的。
int reserve() 返回可以预约座位的 最小编号 ，此座位变为不可预约。
void unreserve(int seatNumber) 将给定编号 seatNumber 对应的座位变成可以预约。

*/

class SeatManager {
   public:
    set<int> seats;  // member, takes seat num as element
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            (this->seats).insert(i);
        }
    }

    int reserve() {
        int seat = *(seats.begin());
        seats.erase(seat);
        return (seat);
    }

    void unreserve(int seatNumber) {
        (this->seats).insert(seatNumber);
    }
};

// Your SeatManager object will be instantiated and called as such:
int main() {
    int n = 5;
    int seatNumber = 2;
    SeatManager* obj = new SeatManager(n);
    int param_1 = obj->reserve();
    obj->unreserve(seatNumber);
}
