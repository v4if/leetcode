//
// Created by root on 9/14/17.
//

#include <iostream>
#include <queue>
#include <stack>
#include <gtest/gtest.h>

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
 * */

using namespace std;

namespace symmetric_tree {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    TreeNode* stringToTreeNode(string input) {
        input = input.substr(1, input.size() - 2);
        if (!input.size()) {
            return nullptr;
        }

        stringstream ss;
        ss.str(input);
        string item;

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (true) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) {
                break;
            }
            if ("null" != item) {
                node->left = new TreeNode(stoi(item));
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ',')) {
                break;
            }
            if ("null" != item) {
                node->right = new TreeNode(stoi(item));
                nodeQueue.push(node->right);
            }
        }

        return root;
    }

    bool helper(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;

        return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root->left, root->right);
    }

    bool isSymmetricBFS(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode* t1 = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* t2 = nodeQueue.front();
            nodeQueue.pop();

            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;

            if (t1->val != t2->val) return false;

            nodeQueue.push(t1->left);
            nodeQueue.push(t2->right);
            nodeQueue.push(t1->right);
            nodeQueue.push(t2->left);
        }

        return true;
    }
}

TEST(leetcode, leetcode_symmetric_tree_Test) {
    using namespace symmetric_tree;
    TreeNode* root = stringToTreeNode("[1,2,2,3,4,4,3]");

    std::cout << isSymmetricBFS(root) << std::endl;
}