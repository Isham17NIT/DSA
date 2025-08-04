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
    ListNode* findKthNode(ListNode* head,int k)
    {
        ListNode* temp=head;
        while(k>1 && temp->next)
        {
            temp=temp->next;
            k--;
        }
        return k>1 ? nullptr : temp;
    }
    ListNode* reverseLL(ListNode* &ptr1, ListNode* &ptr2)
    {
        ListNode* prevptr=nullptr, *curr=ptr1, *nextptr=ptr1->next;
        while(curr!=ptr2)
        {
            curr->next=prevptr;
            prevptr=curr;
            curr=nextptr;
            nextptr=nextptr->next;
        }
        curr->next=prevptr;
        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || !head->next || k==1)
            return head;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        temp->next=head;
        ListNode* ptr1=nullptr, *ptr2=nullptr;
        while(temp->next)
        {
            ptr1=temp->next;
            ptr2=findKthNode(ptr1,k);
            if(!ptr2) //less than k nodes in current iteration
                break;
            ListNode* nextptr=ptr2->next;
            reverseLL(ptr1,ptr2);
            //ptr2 will become my newHead
            temp->next=ptr2;
            ptr1->next=nextptr;
            temp=ptr1;
        }
        return dummy->next;
    }
};