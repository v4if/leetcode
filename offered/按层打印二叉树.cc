#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void printFromTopToBottom(BinaryTreeNode* pTreeRoot) {
	if (pTreeRoot == NULL) return;
	
	deque<BinaryTreeNode*> dq;
	dq.push_back(pTreeRoot);
	while(!dq.empty()) {
		BinaryTreeNode* node = dq.front();
		dq.pop_front();
		
		cout << node->m_nValue;
		
		if (node->m_pLeft) dq.push_back(node->m_pLeft);
		if (node->m_pRight) dq.push_back(node->m_pRight);
	}
}
