/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* getLeft(TreeLinkNode* root) {
        if (root == NULL) return NULL;
        while(root && root->left!= NULL) root = root->left;
        return root;
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL) return NULL;
        if (pNode->right) return getLeft(pNode->right);
        
        // 寻找左链
        TreeLinkNode* parent = pNode->next;
        TreeLinkNode* cur = pNode;
        while(parent) {
            if (parent->left == cur) return parent;
            cur = parent;
            parent = parent->next;
        }
        return NULL;
    }
};
