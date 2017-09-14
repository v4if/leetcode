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

namespace binary_tree_zigzag_level_order_traversal {
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        vector<vector<int>> ret;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        bool zigzag = true;
        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();
            vector<int> level(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();

                int index = zigzag ? i : size -i - 1;
                level[index] = node->val;
                if (node->left)
                    nodeQueue.push(node->left);
                if (node->right)
                    nodeQueue.push(node->right);
            }
            zigzag = !zigzag;
            ret.push_back(level);
        }
        return ret;
    }
}

TEST(leetcode, binary_tree_zigzag_level_order_traversal) {
    using namespace binary_tree_zigzag_level_order_traversal;
    TreeNode* root = stringToTreeNode("[1,2,3,4,null,null,5]");

    vector<vector<int>> result = zigzagLevelOrder(root);
    string out;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            out += to_string(result[i][j]) + ", ";
        }
        out = out.substr(0, out.size() - 2) + "\n";
    }

    std::cout << out << std::endl;
}