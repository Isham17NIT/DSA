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
    ListNode* reverseLL(ListNode* head,ListNode* tail)
    {
        ListNode* prev=nullptr, *curr=head, *temp=curr->next;
        while(curr!=tail)
        {
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        return curr;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(!head || !head->next || left==right)
            return head;
        ListNode* ptr1=head, *ptr2=head, *prevptr1=head, *nextptr2=head;
        int i=0;
        while(i<left-1){
            i+=1;
            prevptr1=ptr1;
            ptr1=ptr1->next;
        }
        i=0;
        while(i<right-1){
            i+=1;
            ptr2=ptr2->next;
            nextptr2=ptr2->next;
        }
        ListNode* newHead = reverseLL(ptr1,ptr2);
        if(ptr1==head && ptr2->next==nullptr) //full list has to reversed
            return newHead;
        else if(ptr1==head)
        {
            ListNode* temp = newHead;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=nextptr2;
            return newHead;
        }
        else if(ptr2->next==nullptr)
        {
            prevptr1->next=newHead;
            return head;
        }
        //else ---> sublist in middle
        prevptr1->next=newHead;
        ListNode* temp = newHead;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=nextptr2;
        return head;
    }
};