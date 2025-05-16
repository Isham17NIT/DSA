/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* head = nullptr, *temp = nullptr;
        priority_queue<pair<int,ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq; //minHeap
        for(ListNode* l : lists)
        {
            if(l)
                pq.push({l->val,l});
        }
        while(!pq.empty())
        {
            pair<int,ListNode*> p = pq.top();
            pq.pop();
            if(head==nullptr)
            {
                head=new ListNode(p.second->val);
                temp=head;
            }
            else
            {
                temp->next = new ListNode(p.second->val);
                temp=temp->next;
            }
                
            if(p.second->next)
                pq.push({p.second->next->val, p.second->next});
        }
        return head;
    }
};