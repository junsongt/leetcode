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

// 383. 赎金信
/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
*/

bool canConstruct(string ransomNote, string magazine) {
    int i = 0;
    int j = 0;
    bool res = false;
    int match = 0;

    for (int i = 0; i < ransomNote.length(); i++) {
        for (int j = 0; j < magazine.length(); j++) {
            if (ransomNote[i] == magazine[j]) {
                match++;
                magazine.erase(j, 1);
                break;
            }
        }
    }
    if (match == ransomNote.length()) {
        res = true;
    }
    // while (i < magazine.length()) {
    //     if (magazine[i] == ransomNote[j]) {
    //         i++;
    //         j++;
    //     }
    //     else {
    //         i++;
    //         j = 0;
    //     }
    //     if (j == ransomNote.length()) {
    //         res = true;
    //     }
    // }

    return res;
}