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
class Solution {
private:
    struct Compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        priority_queue<ListNode*,vector<ListNode*>, Compare> pq;
        for(ListNode* l : lists)
        {
            if(l)
                pq.push(l);
        }
        while(!pq.empty())
        {
            ListNode* l=pq.top();
            pq.pop();
            if(l->next)
                pq.push(l->next);
            temp->next=l;
            temp=temp->next;
        }
        return dummy->next;
    }
};