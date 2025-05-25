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

// 2131. 连接两字母单词得到的最长回文串
/*
给你一个字符串数组 words 。words 中每个元素都是一个包含 两个 小写英文字母的单词。

请你从 words 中选择一些元素并按 任意顺序 连接它们，并得到一个 尽可能长的回文串 。每个元素 至多 只能使用一次。

请你返回你能得到的最长回文串的 长度 。如果没办法得到任何一个回文串，请你返回 0 。

回文串 指的是从前往后和从后往前读一样的字符串。
*/

int longestPalindrome(vector<string>& words) {
    int n = words.size();
    unordered_map<string, int> dict;
    for (int i = 0; i < n; i++) {
        string word = words[i];
        auto it = dict.find(word);
        if (it == dict.end()) {
            dict[words[i]] = 1;
        } else {
            (it->second)++;
        }
    }

    int res = 0;
    bool center = false;  // to determine if there exists "aa" in the middle
    for (auto it = dict.begin(); it != dict.end(); it++) {
        string word = it->first;
        string word_dual = string(1, word[1]) + string(1, word[0]);  // word's mirror
        int cnt = it->second;
        // if this word is palindrome itself: "aa"
        if (word == word_dual) {
            if (cnt % 2 == 1) {
                center = true;
            }
            res += 4 * (cnt / 2);
        } else {
            if (dict.find(word_dual) != dict.end() && cnt != 0) {
                int cnt_dual = dict[word_dual];
                res += 4 * min(cnt, cnt_dual);
                dict[word_dual] = 0;  // to avoid counting word's mirror again
            }
        }
    }
    // adding the center self-palindrome "aa"
    if (center) {
        res += 2;
    }
    return res;
}