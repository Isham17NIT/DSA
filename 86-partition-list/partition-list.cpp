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
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head || !head->next)
            return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=head, *i=dummy, *prevptr=head;
        while(temp)
        {
            if(temp->val < x)//keep on adding to the i-list
            {
                if(i->next==temp)
                    i=i->next;
                else
                {
                    prevptr->next=temp->next;
                    temp->next=i->next;
                    i->next=temp;
                    temp=prevptr;
                    i=i->next;
                }    
            }
            prevptr=temp;
            temp=temp->next;
        }
        return dummy->next;
    }
};