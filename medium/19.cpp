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

// 19. 删除链表的倒数第 N 个结点

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int len(ListNode* head) {
    int n = 0;
    while (head != nullptr) {
        n++;
        head = head->next;
    }
    return n;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int m = len(head);
    int pos = 1;
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (pos != m - n + 1 && curr != nullptr) {
        prev = curr;
        curr = curr->next;
        pos++;
    }
    // prev != NULL, we are deleting non-head;
    // else, we will have new head
    if (prev != nullptr) {
        prev->next = curr->next;
        curr = nullptr;
        return head;
    } else {
        curr = head->next;
        head = nullptr;
        return curr;
    }
}