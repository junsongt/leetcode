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

// 2207. 字符串中最多数目的子序列
/*
给你一个下标从 0 开始的字符串 text 和另一个下标从 0 开始且长度为 2 的字符串 pattern ，两者都只包含小写英文字母。

你可以在 text 中任意位置插入 一个 字符，这个插入的字符必须是 pattern[0] 或者 pattern[1] 。注意，这个字符可以插入在 text 开头或者结尾的位置。

请你返回插入一个字符后，text 中最多包含多少个等于 pattern 的 子序列 。

子序列 指的是将一个字符串删除若干个字符后（也可以不删除），剩余字符保持原本顺序得到的字符串。
*/

long long maximumSubsequenceCount(string text, string pattern) {
    int n = text.size();
    // basic logic is: optimally, head placed at the front or tail placed at ehe back, if a head is placed in between after some tail, then we lose a chance to form a subsequence
    char head = pattern[0];
    char tail = pattern[1];
    // if head = tail, just count # of head or tail plus one head/tail at the front/back, then (n+1) choose 2
    if (head == tail) {
        long long sum = 0;
        for (char c : text) {
            if (c == head) {
                sum++;
            }
        }
        return ((sum + 1) * sum) / 2;
    }

    long long heads_so_far = 0;
    long long mode_1 = 0;  // acc_sum for mode for adding head to the front
    long long mode_2 = 0;  // acc_sum for mode for adding tail to the rear

    for (char c : text) {
        // if head, accumulate the counts of head
        if (c == head) {
            heads_so_far++;
        }
        // if tail, it can link with all previous heads, hence its contribution is all previous # of heads, then accumulate total# of subsequence
        // In mode 1, we have 1 addtional head at the front, so contribution+1
        // In mode 2, contribution stays the same, we will deal with the last tail at the end
        if (c == tail) {
            mode_1 += (heads_so_far + 1);
            mode_2 += heads_so_far;
        }
    }
    // In mode 2, the last tail has its contribution = all heads before it
    mode_2 += heads_so_far;
    return max(mode_1, mode_2);
}

// leetcode solution (handles same char case)
long long maximumSubsequenceCount(string text, string pattern) {
    long long res = 0;
    int cnt1 = 0, cnt2 = 0;
    for (char c : text) {
        if (c == pattern[1]) {
            res += cnt1;
            cnt2++;
        }
        if (c == pattern[0]) {
            cnt1++;
        }
    }
    return res + max(cnt1, cnt2);
}