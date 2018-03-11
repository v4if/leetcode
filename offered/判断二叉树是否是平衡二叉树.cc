//输入一棵二叉树，判断该二叉树是否是平衡二叉树。

class Solution {
public:
    int depth(TreeNode* root, bool& flag) {
        if (root == NULL) return 0;
        
        int left = depth(root->left, flag);
        int right = depth(root->right, flag);
        flag = flag && (abs(left-right) <= 1) ? true : false;
        return ::max(left, right) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL) return true;
        bool flag = true;
        depth(pRoot, flag);
        return flag;
    }
    
/*
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return ::max(depth(root->left), depth(root->right)) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL) return true;
        return abs(depth(pRoot->left) - depth(pRoot->right)) <= 1 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
*/
};
