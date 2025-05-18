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

// 2901. 最长相邻不相等子序列 II
/*
给定一个字符串数组 words ，和一个数组 groups ，两个数组长度都是 n 。

两个长度相等字符串的 汉明距离 定义为对应位置字符 不同 的数目。

你需要从下标 [0, 1, ..., n - 1] 中选出一个 最长子序列 ，将这个子序列记作长度为 k 的 [i0, i1, ..., ik - 1] ，它需要满足以下条件：

相邻 下标对应的 groups 值 不同。即，对于所有满足 0 < j + 1 < k 的 j 都有 groups[ij] != groups[ij + 1] 。
对于所有 0 < j + 1 < k 的下标 j ，都满足 words[ij] 和 words[ij + 1] 的长度 相等 ，且两个字符串之间的 汉明距离 为 1 。
请你返回一个字符串数组，它是下标子序列 依次 对应 words 数组中的字符串连接形成的字符串数组。如果有多个答案，返回任意一个。

子序列 指的是从原数组中删掉一些（也可能一个也不删掉）元素，剩余元素不改变相对位置得到的新的数组。

注意：words 中的字符串长度可能 不相等 。
*/

vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    auto hamming = [](string& a, string& b) -> int {
        if (a.size() != b.size()) {
            return -1;
        } else {
            int dist = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) {
                    dist++;
                }
            }
            return dist;
        }
    };
    int n = groups.size();
    vector<int> dp(n, 1);  // dp[i] = length of the longest valid subsequence ending at word i
    vector<string> res;
    int max_i = 0;
    vector<int> parent(n, -1);  // parent[i] = index of the previous word before word i in this best sequence
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (hamming(words[i], words[j]) == 1 &&
                groups[i] != groups[j] &&
                dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[max_i] < dp[i]) {
            max_i = i;  // max_i is the last index of such subseq
        }
    }

    // if you trace back parent from max_i, then parent[max_i] is the index of the previous word in the subsequence, and once prev_idx = parent[max_i], the previous previous index in the subseq is parent[prev_idx], so on and so forth
    int idx = max_i;
    while (idx != -1) {
        res.push_back(words[idx]);
        idx = parent[idx];
    }
    reverse(res.begin(), res.end());
    return res;
}