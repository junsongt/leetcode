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

int findJudge(int n, vector<vector<int>>& trust) {
    int m = trust.size();
    vector<int> stat(n);  // the statistics of "net trust credits" of people
    // note that since people are 1 ~ n integers so we use array, and (index+1) is the person's id.
    // We could also use map.
    // if someone gets trust, then his credit gets +1; if he sends out trust, then his credit gets -1.
    // Our goal is to find someone with net credit = n-1, i.e. he does not ever sent out trust, he only gets trust from anyone else.

    for (int i = 0; i < m; i++) {
        int start = trust[i][0];  // person who sends out trust
        int dest = trust[i][1];   // person who gets trust
        stat[start - 1]--;
        stat[dest - 1]++;
    }
    for (int i = 0; i < n; i++) {
        if (stat[i] == n - 1) {
            return i + 1;
        }
    }
    return -1;

    // map<int, int> stat;
    // for (int i = 0; i < m; i++) {
    //     int start = trust[i][0];
    //     int dest = trust[i][1];
    //     auto it_1 = stat.find(start);
    //     auto it_2 = stat.find(dest);
    //     if (it_1 == stat.end()) {
    //         stat[start] = -1;
    //     } else {
    //         (it_1->second)--;
    //     }
    //     if (it_2 == stat.end()) {
    //         stat[dest] = 1;
    //     } else {
    //         (it_2->second)++;
    //     }
    // }

    // for (auto it : stat) {
    //     if (it.second == n-1) {
    //         return it.first;
    //     }
    // }
    // return -1;
}