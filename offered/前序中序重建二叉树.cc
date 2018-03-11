/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bt(vector<int> pre, vector<int> vin, int preFront, int preBack, int vinFront, int vinBack) {
        if (preFront > preBack || vinFront > vinBack) return NULL;
        
        TreeNode* node = new TreeNode(pre[preFront]);
        
        int idx = vinFront;
        for (;idx < vinBack;idx++) {
            if (vin[idx]==pre[preFront]) break;
        }
        
        node->left = bt(pre, vin, preFront+1,preFront+idx-vinFront, vinFront, idx-1);
        node->right = bt(pre, vin, preFront+idx-vinFront+1, preBack, idx+1, vinBack);
        
        return node;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty()||vin.empty()) return NULL;
        return bt(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }
};
