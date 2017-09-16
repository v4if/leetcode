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

namespace convert_sorted_array_to_bst {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start >= end) return nullptr;

        int index = (start + end) >> 1;
        TreeNode* node = new TreeNode(nums[index]);
        node->left = helper(nums, start, index);
        node->right = helper(nums, index + 1, end);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()
        );
    }

    void treeToString(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != NULL) treeToString(root->left);
        std::cout << to_string(root->val) + "  ";
        if (root->right != NULL) treeToString(root->right);
    }
}

TEST(leetcode, convert_sorted_array_to_bst) {
    using namespace convert_sorted_array_to_bst;

    vector<int> nums{1, 2, 3};
    TreeNode* root = sortedArrayToBST(nums);
    treeToString(root);
    std::cout << std::endl;
}