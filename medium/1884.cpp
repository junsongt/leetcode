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

// 1884. 鸡蛋掉落-两枚鸡蛋
/*
给你 2 枚相同 的鸡蛋，和一栋从第 1 层到第 n 层共有 n 层楼的建筑。

已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都 会碎 ，从 f 楼层或比它低 的楼层落下的鸡蛋都 不会碎 。

每次操作，你可以取一枚 没有碎 的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。

请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
*/

/*
Idea:
Let f(i) be the ith test floor number to test drop the egg, then every time we test drop at f(i), we have 2 decision paths:
         No: move to f(i+1)
f(i)---->
         Yes: count [f(i-1)+1, f(i)-1] + i = (f(i) - f(i-1) - 1) + i to be the potential min number of test
Suppose there are k number of test floors, the overall min number of tests = k, which is when the worst case happens that we don't break the egg at every test floor and go through every test floor. Any number bigger than k is not optimal, so we want the number of tests = k at every test floor i, Note that the number of tests at ith test floor is: (f(i) - f(i-1) - 1) + i. So we have:
f(k) - f(k-1) - 1 + k = k ====> f(k)-f(k-1)=1
f(k-1) - f(k-2) - 1 + k-1 = k ====> f(k-1)-f(k-2)=2
...

total number of floors: n = delta_1 + delta_2 + ... + delta_{k-1} + remainder
                              = 1 + 2 + 3 + ... + k-1 + remainder
0 <= remainder <= k



*/
int twoEggDrop(int n) {
    int delta = 1;  // delta_1 = f(k) - f(k-1)
    int level = 0;  // level counts the number of test floor from top floor to bottom

    // loop until hit the remainder since delta_k = k
    while (n > delta) {
        n -= delta;
        level++;
        delta++;
    }
    // now n = remainder and level = k - 1
    return max(level + 1, n);
}