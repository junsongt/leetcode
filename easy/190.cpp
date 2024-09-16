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

// 190. 颠倒二进制位
/*
颠倒给定的 32 位无符号整数的二进制位。

提示：

请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数 -1073741825。
*/

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int i = 0;
    while (n > 0) {
        // "& 1" could extract last digit; move it to left 31-i position
        res = res + ((n & 1) << (31 - i));
        n = n >> 1;
        i++;
    }
    return res;
}