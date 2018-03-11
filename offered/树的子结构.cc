/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool rootCheck(TreeNode* r1, TreeNode* r2) {
        if (r2==NULL) return true;
        if (r1 == NULL ) return false;
        
        return r1->val==r2->val && rootCheck(r1->left, r2->left) && rootCheck(r1->right, r2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 ==NULL) return false;
        
        return rootCheck(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
