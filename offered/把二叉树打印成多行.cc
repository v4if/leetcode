// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if (pRoot == NULL) return res;
            
            deque<TreeNode*> dq;
            dq.push_back(pRoot);
            deque<TreeNode*> nextDq;
            while(!dq.empty()) {
                int sz = dq.size();
                vector<int> line;
                for (int i = 0;i < sz;i++) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    
                    line.push_back(node->val);
                    if (node->left) nextDq.push_back(node->left);
                    if (node->right) nextDq.push_back(node->right);
                }
                res.push_back(line);
                swap(dq, nextDq);
            }
            return res;
        }
    
};
