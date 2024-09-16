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

// 58. 最后一个单词的长度

/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

*/

int lengthOfLastWord(string s) {
    int back_parser = s.length() - 1;
    while (s[back_parser] == ' ') {
        back_parser--;
    }
    int start = back_parser;
    while (back_parser >= 0 && s[back_parser] != ' ') {
        back_parser--;
    }
    return start - back_parser;
}