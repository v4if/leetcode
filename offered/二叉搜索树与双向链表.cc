/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void bt(TreeNode* root, TreeNode*& prev) {
        if (root == NULL) return;
        
        if (root->left)  bt(root->left, prev);
        root->left = prev;
        if (prev) {
            prev->right = root;
        }
        prev = root;
        if (root->right) bt(root->right, prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* prev = NULL;
        bt(pRootOfTree, prev); 
        
        TreeNode* head = pRootOfTree;
        while(head && head->left) {
            head = head->left;
        }
        return head;
    }
};
