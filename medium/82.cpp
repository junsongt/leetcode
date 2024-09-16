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

// 82. 删除排序链表中的重复元素 II
/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    // set up a repeat ref
    int rep = -101;
    while (curr != nullptr) {
        int val = curr->val;
        // if curr has repeat, keep deleting
        while (curr->next != nullptr && curr->next->val == val) {
            rep = val;  // set repeat ref value
            // delete and recycle node
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
            temp = nullptr;
        }
        // make sure the last one in the repeat line is deleted, and re-link prev and head
        if (curr->val == rep) {
            // delete and recycle node
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
            temp = nullptr;

            // re-link prev and head
            if (prev == nullptr) {
                head = curr;
            } else {
                prev->next = curr;
            }
        }
        // for regular ones, keep moving
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}