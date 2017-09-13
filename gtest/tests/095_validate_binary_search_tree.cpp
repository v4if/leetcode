//
// Created by root on 9/13/17.
//

#include <iostream>
#include <queue>
#include <gtest/gtest.h>

/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
 * */

using namespace std;

namespace validate_binary_search_tree {
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

    void inorderTraversalRecursive(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != NULL) inorderTraversalRecursive(root->left);
        std::cout << to_string(root->val) + "  ";
        if (root->right != NULL) inorderTraversalRecursive(root->right);
    }
    bool helper(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!helper(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return helper(node->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return helper(root, prev);
    }
}

TEST(leetcode, validate_binary_search_tree) {
    using namespace validate_binary_search_tree;
    TreeNode* root = stringToTreeNode("[10,5,15,null,null,6,20]");
    inorderTraversalRecursive(root);

    std::cout << isValidBST(root) << std::endl;
}