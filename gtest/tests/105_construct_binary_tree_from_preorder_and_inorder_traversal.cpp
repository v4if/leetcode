//
// Created by root on 9/15/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*

 * */

using namespace std;

namespace solve_first {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
}

TEST(leetcode, template) {

}