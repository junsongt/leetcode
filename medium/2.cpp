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

// 2. 两数相加
/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

//* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int incre(int v) {
    if (v > 9) {
        return 1;
    } else {
        return 0;
    }
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode((l1->val + l2->val) % 10);
    int temp = (l1->val + l2->val) > 9;  // digit increment, either 0 or 1
    ListNode* curr = head;
    l1 = l1->next;
    l2 = l2->next;
    while (l1 != nullptr && l2 != nullptr) {
        int v = l1->val + l2->val + temp;
        curr->next = new ListNode(v % 10);
        temp = incre(v);
        curr = curr->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == nullptr) {
        while (l2 != nullptr) {
            int v = l2->val + 0 + temp;
            curr->next = new ListNode(v % 10);
            temp = incre(v);
            curr = curr->next;
            l2 = l2->next;
        }
    } else {
        while (l1 != nullptr) {
            int v = l1->val + 0 + temp;
            curr->next = new ListNode(v % 10);
            temp = incre(v);
            curr = curr->next;
            l1 = l1->next;
        }
    }
    if (temp == 1) {
        curr->next = new ListNode(1);
    }
    return head;
}