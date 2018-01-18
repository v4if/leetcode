/**
priority_queue本质是一个堆。

1. 头文件是#include<queue>

2. 关于priority_queue中元素的比较

　　模板申明带3个参数：priority_queue<Type, Container, Functional>，其中Type 为数据类型，Container为保存数据的容器，Functional 为元素比较方式。

　　Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector。

2.1 比较方式默认用operator<，所以如果把后面2个参数缺省的话，优先队列就是大顶堆（降序），队头元素最大。特别注意pair的比较函数。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    class Cmp
    {
    public:
        bool operator() (ListNode *a, ListNode *b) const
        {
            return a->val > b->val;
        }
    };    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
        ListNode *head = NULL;
        ListNode *cur = NULL;
        int k = lists.size();
        if(k == 0)
        {
            return NULL;
        }
        for(ListNode *list: lists)
        {
            if(list != NULL)
            {
                pq.push(list);  
            }     
        }
        while( !pq.empty() )
        {
            ListNode *next = pq.top();
            pq.pop();
            if(next->next != NULL)
            {
                pq.push(next->next);
            }
            next->next = NULL;
            if(head == NULL)
            {
                head = next;
                cur = head;
            }
            else
            {
                cur->next = next;
                cur = cur->next;                   
            }            
        }
        return head;
    }
};
