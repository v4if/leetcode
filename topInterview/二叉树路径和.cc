/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
    void bt(TreeNode* root, int expect, vector<int>& result, vector<vector<int>>& arr){
        expect -= root->val;
        result.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            if (expect == 0) arr.push_back(result);
        }
        
        if (root->left) bt(root->left, expect, result, arr);
        if (root->right) bt(root->right, expect, result, arr);
        result.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL) return vector<vector<int>>{};
        
        vector<vector<int>> arr;
        vector<int> result;
        bt(root, expectNumber, result, arr);
        return arr;
    }
};
