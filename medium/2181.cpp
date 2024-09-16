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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 2181. 合并零之间的节点
/*
给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。

对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0 。

 返回修改后链表的头节点 head 。
*/

ListNode* mergeNodes(ListNode* head) {
    ListNode* curr = head;
    // 如果不是只有一个0Node， 那么至少有这样的结构：0->(...)->0
    if (curr->next != nullptr) {
        // 第一步先把第一个0->(...)->0结构中的(...)变成head
        curr = curr->next;
        int temp = 0;
        while (curr->val != 0) {
            temp += curr->val;
            curr = curr->next;
        }
        ListNode* head_new = new ListNode(temp);
        ListNode* curr_new = head_new;  // 至此，新的head完成
        // 需要清零temp
        temp = 0;
        // 然后越过边界的0去看下面是否还有->(...)->0的结构
        curr = curr->next;
        // 探索过程
        while (curr != nullptr) {
            if (curr->val == 0) {
                // 如果有， 新建下个节点，把之前累计的temp注入Node值， 然后连接节点并移步指针，最后清零temp准备重新计数累加
                ListNode* next = new ListNode(temp);
                curr_new->next = next;
                curr_new = next;
                temp = 0;
            } else {
                // 如果还没碰到0， 就继续累加temp
                temp += curr->val;
            }
            curr = curr->next;
        }
        return head_new;
    }
    // 如果就一个0Node， 那么去掉0就只剩个空列表，返回空指针
    else {
        return nullptr;
    }
}