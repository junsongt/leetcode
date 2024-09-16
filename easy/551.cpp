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

// 551. 学生出勤记录 I
/*
给你一个字符串 s 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：

'A'：Absent，缺勤
'L'：Late，迟到
'P'：Present，到场
如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：

按 总出勤 计，学生缺勤（'A'）严格 少于两天。
学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
如果学生可以获得出勤奖励，返回 true ；否则，返回 false 。
*/
bool checkRecord(string s) {
    int ctr_A = 0;
    int ctr_L = 0;

    for (char c : s) {
        if (c == 'L') {
            ctr_L++;
            if (ctr_L == 3) {
                return false;
            }
        } else {
            ctr_L = 0;
            if (c == 'A') {
                ctr_A++;
            }
        }
    }
    return (ctr_A < 2 && ctr_L < 3);
}