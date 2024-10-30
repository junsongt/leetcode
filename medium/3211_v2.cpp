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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void build_tree(TreeNode* root, int level) {
    if (level != 0) {
        if (root->val == 0) {
            root->right = new TreeNode(1);
            build_tree(root->right, level - 1);
        } else {
            root->left = new TreeNode(0);
            root->right = new TreeNode(1);
            build_tree(root->left, level - 1);
            build_tree(root->right, level - 1);
        }
    }
}

bool leaf(TreeNode* root) {
    return (root->left == nullptr) && (root->right == nullptr);
}

// find all paths from root to leaf, return an array of paths
vector<string> path(TreeNode* root, string traversed) {
    if (leaf(root)) {
        traversed += to_string(root->val);
        return vector<string>{traversed};
    } else if (root->left == nullptr) {
        traversed += to_string(root->val);
        return path(root->right, traversed);
    } else {
        if (root->val != -1) {
            traversed += to_string(root->val);
        }
        vector<string> path_left = path(root->left, traversed);
        vector<string> path_right = path(root->right, traversed);
        path_left.insert(path_left.end(), path_right.begin(), path_right.end());
        return path_left;
    }
}

vector<string> validStrings(int n) {
    TreeNode* root = new TreeNode(-1);
    build_tree(root, n);
    return path(root, "");
}