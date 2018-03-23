BinaryNode* GetLastCommonAncestor(BinaryNode* root, BinaryNode* node1, BinaryNode* node2)  
{  
    if (root == NULL || node1 == NULL || node2 == NULL)  
        return NULL;  
  
    if (node1 == root || node2 == root)  
        return root;  
  
    BinaryNode* cur = NULL;  
  
    BinaryNode* left_lca = GetLastCommonAncestor(root->_left, node1, node2);  
    BinaryNode* right_lca = GetLastCommonAncestor(root->_right, node1, node2);  
    if (left_lca && right_lca)  
        return root;  
    if (left_lca == NULL)  
        return right_lca;  
    else  
        return left_lca;  
}  
