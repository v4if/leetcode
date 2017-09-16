//
// Created by root on 9/16/17.
//

#include <iostream>
#include <queue>
#include <gtest/gtest.h>

/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 * */

using namespace std;

namespace populating_next_right_pointers_in_each_node {
    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
        TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
    };

    TreeLinkNode* stringToTree(string input) {
        input = input.substr(1, input.size() - 2);
        if (!input.size()) return nullptr;

        stringstream ss;
        ss.str(input);
        string item;
        getline(ss, item, ',');
        TreeLinkNode* root = new TreeLinkNode(stoi(item));

        queue<TreeLinkNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeLinkNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ','))
                break;
            if ("null" != item) {
                node->left = new TreeLinkNode(stoi(item));
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ','))
                break;
            if ("null" != item) {
                node->right = new TreeLinkNode(stoi(item));
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    string treeToString(TreeLinkNode* node) {
        if (node == NULL) return string();

        string out;
        out += treeToString(node->left);
        out += to_string(node->val) + ", ";
        out += treeToString(node->right);
        return out;
    }

    void connect(TreeLinkNode *root) {
        TreeLinkNode* levelStart = root;
        while (levelStart != NULL) {
            TreeLinkNode* cur = levelStart;
            while (cur != NULL) {
                if (cur->left) cur->left->next = cur->right;
                if (cur->right && cur->next) cur->right->next = cur->next->left;

                cur = cur->next;
            }
            levelStart = levelStart->left;
        }
    }
}

TEST(leetcode, populating_next_right_pointers_in_each_node_test) {
    using namespace populating_next_right_pointers_in_each_node;
    TreeLinkNode* root = stringToTree("[1,2,3,4,5,6,7]");
    string out = treeToString(root);
    cout << out.substr(0, out.size() - 2) + "\n";
}