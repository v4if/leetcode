#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v):val(v), left(NULL), right(NULL){}
};

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

void travel(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    travel(root->left);
    travel(root->right);
}

int main(){
    char buff[] = {"|1||2||4|###|3|##"};
    TreeNode* root = Deserialize(buff);
    travel(root); cout << endl;

    char* str = Serialize(root);
    cout << str << endl;
    delete str;
}
