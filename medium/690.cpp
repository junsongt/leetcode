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

// 690. 员工的重要性
/*
你有一个保存员工信息的数据结构，它包含了员工唯一的 id ，重要度和直系下属的 id 。

给定一个员工数组 employees，其中：

employees[i].id 是第 i 个员工的 ID。
employees[i].importance 是第 i 个员工的重要度。
employees[i].subordinates 是第 i 名员工的直接下属的 ID 列表。
给定一个整数 id 表示一个员工的 ID，返回这个员工和他所有下属的重要度的 总和。

*/

// Definition for Employee.
class Employee {
   public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, int> dict;  // hash map for (id, index)
    queue<Employee*> wl;
    int res = 0;
    // set up id <-> index relation for sake of quick search by id
    for (int i = 0; i < employees.size(); i++) {
        auto e = employees[i];
        int j = e->id;
        if (dict.find(j) == dict.end()) {
            dict[j] = i;
        }
    }

    // BFS
    wl.push(employees[dict[id]]);
    while (!wl.empty()) {
        Employee* curr = wl.front();
        res += curr->importance;
        vector<int> subs = curr->subordinates;
        // push children
        for (int i : subs) {
            wl.push(employees[dict[i]]);
        }
        wl.pop();
    }
    return res;
}