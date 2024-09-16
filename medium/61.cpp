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

// 61. 旋转链表
/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// input head should not be NULL
ListNode* rotate(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr) {
        return head;
    } else {
        curr->next = head;
        prev->next = nullptr;
        return curr;
    }
}

int len(ListNode* head) {
    ListNode* curr = head;
    int n = 0;
    while (curr != nullptr) {
        n = n + 1;
        curr = curr->next;
    }
    return n;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) {
        return head;
    }
    int n = len(head);
    k = k % n;
    while (k > 0) {
        // rotate once
        head = rotate(head);
        k--;
    }
    return head;
}