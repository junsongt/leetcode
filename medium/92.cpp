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

// 92. 反转链表 II
/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) {
        return head;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;

    int pos = 1;
    while (pos < left) {
        prev = curr;
        curr = curr->next;
        pos++;
    }
    ListNode* ll = prev;
    ListNode* start = curr;

    // reverse the section [left, right]
    while (pos <= right) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
        pos++;
    }
    // if ll is NUll, then prev has nothing ahead, so prev must be new head
    // else, head remains the new head
    if (ll != nullptr) {
        ll->next = prev;
        start->next = curr;
        return head;
    } else {
        start->next = curr;
        return prev;
    }
}