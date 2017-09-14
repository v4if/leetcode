//
// Created by root on 9/14/17.
//

#include <iostream>
#include <queue>
#include <gtest/gtest.h>

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
 * */

using namespace std;

namespace binary_tree_level_order_traversal {
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

    void helper(TreeNode* node, vector<vector<int>>& path, int depth) {
        if (node == NULL) return;

        if (path.size() == depth) {
            path.push_back(vector<int>());
        }

        path[depth].push_back(node->val);
        helper(node->left, path, depth + 1);
        helper(node->right, path, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        vector<vector<int>> ret;
        helper(root, ret, 0);
        return ret;
    }
}

TEST(leetcode, binary_tree_level_order_traversal) {
    using namespace binary_tree_level_order_traversal;
    TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]");

    vector<vector<int>> result = levelOrder(root);
    string out;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            out += to_string(result[i][j]) + ", ";
        }
        out = out.substr(0, out.size() - 2) + "\n";
    }

    std::cout << out << std::endl;
}