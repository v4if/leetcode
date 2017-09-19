//
// Created by root on 9/19/17.
//

#include <iostream>
#include <queue>
#include <gtest/gtest.h>

/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
 * */

using namespace std;

namespace binary_tree_maximum_path_sum {
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode* stringToTreeNode(string input) {
        input = input.substr(1, input.size() - 2);
        if (!input.size()) return nullptr;

        stringstream ss;
        ss.str(input);

        string item;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) break;
            if (item != "null") {
                node->left = new TreeNode(stoi(item));
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ',')) break;
            if (item != "null") {
                node->right = new TreeNode(stoi(item));
                nodeQueue.push(node->right);
            }
        }

        return root;
    }

    int helper(TreeNode* node, int& maxPath) {
        int left = node->left ? helper(node->left, maxPath) : 0;
        int right = node->right ? helper(node->right, maxPath) : 0;

        maxPath = max(maxPath, node->val + max(left, 0) + max(right, 0));
        return node->val + max(left, max(right, 0));
    }

    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;

        int maxPath = INT32_MIN;
        helper(root, maxPath);
        return maxPath;
    }

    string TreeNodeToString(TreeNode *node) {
        if (node == NULL) return string();

        string out;
        out += node->left ? TreeNodeToString(node->left) : string();
        out += to_string(node->val) + ", ";
        out += node->right ? TreeNodeToString(node->right) : string();
        return out;
    }
}

TEST(leetcode, leetcode_binary_tree_maximum_path_sum__Test) {
    using namespace binary_tree_maximum_path_sum;

    TreeNode* root = stringToTreeNode("[-2,1]");
    string out = TreeNodeToString(root);
    cout << out.substr(0, out.size() - 2) + "\n";

    int maxPath = maxPathSum(root);
    cout << maxPath << endl;
}