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

// 101. 对称二叉树
/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    } else if (p != nullptr && q != nullptr) {
        if (p->val == q->val) {
            return true && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    } else {
        return false;
    }
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return root;
    } else {
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    } else {
        return isSameTree(root->left, invertTree(root->right));
    }
}