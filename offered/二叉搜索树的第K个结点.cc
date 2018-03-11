/*
给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    void getNode(TreeNode* root, int k, int& cur, TreeNode*& node) {
        if (cur > k || root == NULL) return;
        
        if (root->left) getNode(root->left, k, cur, node);
        cur++;
        if (cur == k) node = root;
        if (cur > k) return;
        if (root->right) getNode(root->right, k, cur, node);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode* node = NULL;
        int cur = 0;
        getNode(pRoot, k, cur, node);
        return node;
    }

    
};
