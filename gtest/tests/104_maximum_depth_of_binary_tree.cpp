//
// Created by root on 9/14/17.
//

#include <iostream>
#include <queue>
#include <deque>
#include <gtest/gtest.h>
#include <stack>

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 * */

using namespace std;

namespace maxium_depth_of_binary_tree {
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
    int helper(TreeNode* node) {
        if (node == NULL) return 0;

        int lmax = helper(node->left) + 1;
        int rmax = helper(node->right) + 1;

        return lmax > rmax ? lmax : rmax;
    }

    int maxDepth(TreeNode* root) {
        return helper(root);
    }
}

TEST(leetcode, maxium_depth_of_binary_tree) {
    using namespace maxium_depth_of_binary_tree;
    TreeNode* root = stringToTreeNode("[1,2,3,4,null,null,5]");

    int result = maxDepth(root);

    std::cout << result << std::endl;
}