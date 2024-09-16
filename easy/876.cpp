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

// 876. 链表的中间结点
/*
给你单链表的头结点 head ，请你找出并返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 快慢指针
ListNode* middleNode(ListNode* head) {
    ListNode* middle = head;
    while (head->next != nullptr) {
        head = head->next;
        if (head->next != nullptr) {
            head = head->next;
            middle = middle->next;
        } else {
            middle = middle->next;
        }
    }
    return middle;
}