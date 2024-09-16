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

// 205. 同构字符串
/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    unordered_map<char, char> dict;
    unordered_map<char, char> dict_back;
    int i = 0;
    while (i < s.length()) {
        if (dict.find(s[i]) == nullptr) {
            // deal with surjective case
            if (dict_back.find(t[i]) == nullptr) {
                dict[s[i]] = t[i];
                dict_back[t[i]] = s[i];
                i++;
            } else {
                return false;
            }
        } else {
            auto it = dict.find(s[i]);
            if (it->second == t[i]) {
                i++;
            } else {
                return false;
            }
        }
    }
    return true;
}