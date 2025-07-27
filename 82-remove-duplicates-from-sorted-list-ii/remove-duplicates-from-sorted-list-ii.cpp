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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head; //initially
        ListNode* prev=dummy, *curr=head, *nextptr=head->next;
        int val;
        while(curr)
        {
            nextptr = curr->next;
            if(nextptr && curr->val==nextptr->val)
            {
                val = curr->val;
                while(curr && curr->val==val){
                    prev->next=curr->next;
                    curr=curr->next;
                }
            }
            else{
                curr=curr->next;
                prev=prev->next;
            }
                
        }
        return dummy->next;
    }
};