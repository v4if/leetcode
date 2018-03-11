/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == NULL) return vector<int>{};
        
        deque<TreeNode*> dq;
        vector<int> arr;
        dq.push_back(root);
        while(!dq.empty()) {
            TreeNode* node = dq.front();
            dq.pop_front();
            
            arr.push_back(node->val);
            if (node->left) dq.push_back(node->left);
            if (node->right) dq.push_back(node->right);
        }
        return arr;
    }
};
