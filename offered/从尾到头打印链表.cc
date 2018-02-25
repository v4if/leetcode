#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct List{
	struct List* prev;
	struct List* next;
	T data;
	
	List(T d): data(d), prev(NULL), next(NULL){}
};

List<int>* buildList(vector<int>& nums) {
	typedef List<int> list_t;
	
	list_t dummyHead(0);
	list_t* cur = &dummyHead;
	for (int data : nums) {
		list_t* node = new list_t(data);
		node->prev = cur;
		cur->next = node;
		
		cur = cur->next;
	}
	dummyHead.next->prev = NULL;
	return dummyHead.next;
}

void printList(List<int>* head) {
	List<int>* cur = head;
	while(cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

void reversePrint(List<int>* head) {
	stack<List<int>*> st;
	List<int>* pCur = head;
	while(pCur) {
		st.push(pCur);
		pCur = pCur->next;
	}
	
	while(!st.empty()) {
		pCur = st.top();
		cout << pCur->data << " ";
		st.pop();
	}
	cout << endl;
}

int main() {
    vector<int> nums{1,2,3,4,5};
	List<int>* head = buildList(nums);
	printList(head);

	reversePrint(head);
	
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
