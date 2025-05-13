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

// 3335. 字符串转换后的长度 I
/*
给你一个字符串 s 和一个整数 t，表示要执行的 转换 次数。每次 转换 需要根据以下规则替换字符串 s 中的每个字符：

如果字符是 'z'，则将其替换为字符串 "ab"。
否则，将其替换为字母表中的下一个字符。例如，'a' 替换为 'b'，'b' 替换为 'c'，依此类推。
返回 恰好 执行 t 次转换后得到的字符串的 长度。

由于答案可能非常大，返回其对 109 + 7 取余的结果。
*/

int lengthAfterTransformations(string s, int t) {
    vector<long long> freq(26, 0);
    for (char c : s) {
        int idx = c - 'a';
        freq[idx]++;
    }
    for (int j = 1; j <= t; j++) {
        long long prev_freq = freq[0];
        freq[0] = 0;
        for (int i = 1; i < 26; i++) {
            long long curr_freq = freq[i];
            freq[i] = prev_freq;
            prev_freq = curr_freq;
        }
        freq[0] += prev_freq;
        freq[1] += prev_freq;
    }
    long long res = 0;
    for (long long i : freq) {
        res += i;
    }
    return res;
}
// int lengthAfterTransformations(string s, int t) {
//     const long long MOD = pow(10, 9) + 7;
//     vector<long long> freq(26, 0);
//     for (char c : s) {
//         int idx = c - 'a';
//         // freq[idx]++;
//         freq[idx] = (freq[idx] + 1) % MOD;
//     }
//     for (int j = 1; j <= t; j++) {
//         long long prev_freq = freq[0];
//         freq[0] = 0;
//         for (int i = 1; i < 26; i++) {
//             long long curr_freq = freq[i];
//             freq[i] = prev_freq;
//             prev_freq = curr_freq;
//         }
//         // freq[0] += prev_freq;
//         // freq[1] += prev_freq;
//         freq[0] = (freq[0] + prev_freq) % MOD;
//         freq[1] = (freq[1] + prev_freq) % MOD;
//     }
//     long long res = 0;
//     for (long long i : freq) {
//         // res += i;
//         res = (res + i) % MOD;
//     }
//     return res;
// }