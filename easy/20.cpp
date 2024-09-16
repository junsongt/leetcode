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

// 20. 有效的括号
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/

bool match(char c, char ref) {
    return (c == ')' && ref == '(') || (c == ']' && ref == '[') || (c == '}' && ref == '{');
}
bool isValid(string s) {
    stack<char> my_stack;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if ((c == '(') || (c == '[') || (c == '{')) {
            my_stack.push(c);
        } else {
            if (my_stack.empty()) {
                return false;
            } else {
                char ref = my_stack.top();
                if (match(c, ref)) {
                    my_stack.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return my_stack.empty();
}