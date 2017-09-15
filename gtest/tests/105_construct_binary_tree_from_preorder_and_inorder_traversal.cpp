//
// Created by root on 9/15/17.
//

#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 * */

using namespace std;

namespace construct_binary_tree_from_preorder_and_inorder_traversal {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, vector<int>::iterator iterator,
                     pair<vector<int>::iterator, vector<int>::iterator> interval2) {
        if (interval2.first == interval2.second) return nullptr;

        TreeNode* node = new TreeNode(*iterator);

        auto inorderIterator = std::find(interval2.first, interval2.second, *iterator);
        if (inorderIterator != inorder.end()) {
            node->left = helper(preorder, inorder, iterator + 1, make_pair(interval2.first, inorderIterator));
            node->right = helper(preorder, inorder, iterator + (inorderIterator - interval2.first + 1), make_pair(inorderIterator + 1, interval2.second));
        }

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, preorder.begin(), make_pair(inorder.begin(), inorder.end()));
    }

    void treeToString(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != NULL) treeToString(root->left);
        std::cout << to_string(root->val) + "  ";
        if (root->right != NULL) treeToString(root->right);
    }
}

TEST(leetcode, construct_binary_tree_from_preorder_and_inorder_traversal) {
    using namespace construct_binary_tree_from_preorder_and_inorder_traversal;
    vector<int> preorder{1, 2, 3};
    vector<int> inorder{2,1,3};

    TreeNode* root = buildTree(preorder, inorder);
    treeToString(root);
    std::cout << std::endl;
}