//
// Created by root on 9/12/17.
//

#include <iostream>
#include <vector>
#include <queue>
#include <gtest/gtest.h>
#include <stack>

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
 * */

using namespace std;

namespace binary_tree_inorder_traversal {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    TreeNode* stringToTreeNode(string input) {
        input = input.substr(1, input.size() - 2);

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

            if(!getline(ss, item, ',')) {
                break;
            }

            if (item != "null") {
                int leftNumber = stoi(item);
                node->left = new TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if(!getline(ss, item, ',')) {
                break;
            }

            if (item != "null") {
                int rightNumber = stoi(item);
                node->right = new TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    void inorderTraversalRecursive(TreeNode* root) {
        if (root->left != NULL) inorderTraversalRecursive(root->left);
        std::cout << to_string(root->val) + "  " << std::endl;
        if (root->right != NULL) inorderTraversalRecursive(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stackNode;
        vector<int> ret;
        TreeNode* node = root;

        while (node || !stackNode.empty()) {
            while (node) {
                stackNode.push(node);
                node = node->left;
            }

            node = stackNode.top();
            stackNode.pop();
            ret.push_back(node->val);
            node = node->right;
        }

        return ret;
    }

    string integerVectorToString(vector<int> list, int length = -1) {
        if (length == -1) {
            length = list.size();
        }

        string result;
        for(int index = 0; index < length; index++) {
            int number = list[index];
            result += to_string(number) + ", ";
        }
        return result.substr(0, result.length() - 2);
    }
}

TEST(leetcode, leetcode_binary_tree_inorder_traversal_Test) {
    string input{"[1,null,2,3]"};
    binary_tree_inorder_traversal::TreeNode* root = binary_tree_inorder_traversal::stringToTreeNode(input);
//    inorderTraversalRecursive(root);

    vector<int> ret = binary_tree_inorder_traversal::inorderTraversal(root);
    string out = binary_tree_inorder_traversal::integerVectorToString(ret);
    std::cout << out << std::endl;
}