// 请实现两个函数，分别用来序列化和反序列化二叉树

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
    void btS(TreeNode* root, string& str) {
        if (root == NULL) {
            str.push_back('#');
            return;
        }

        str.push_back('|');
        str += to_string(root->val);
        str.push_back('|');

        btS(root->left, str);
        btS(root->right, str);
    }
    char* Serialize(TreeNode *root) {
        string str;
        btS(root, str);

        int sz = str.size();
        char* buff = new char[sz+1];
        memcpy(buff, str.c_str(), sz);
        buff[sz] = '\0';
        return buff;
    }

    TreeNode* btD(char* str, int& idx, int len) {
        if (idx < len && str[idx] == '#' || idx >= len) {
            idx++;
            return NULL;
        }

        int val = 0;
        if (str[idx] == '|') idx++;
        while(idx < len && str[idx] != '|') {
            val = val * 10 + str[idx] - '0';
            idx++;
        }
        if (str[idx] == '|') idx++;

        TreeNode* node = new TreeNode(val);
        node->left = btD(str, idx, len);
        node->right = btD(str, idx, len);
        return node;
    }
    TreeNode* Deserialize(char *str) {
        int len = strlen(str);
        int idx = 0;
        TreeNode* root = btD(str, idx, len);
        return root;
    }
};






