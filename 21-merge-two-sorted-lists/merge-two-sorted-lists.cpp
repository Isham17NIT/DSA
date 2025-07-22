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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* temp1=list1, *temp2=list2;
        ListNode* head=nullptr, *temp=nullptr;
        while(temp1 && temp2)
        {
            if(temp1->val < temp2->val){
                if(!head){
                    head = temp1;
                    temp = temp1;
                }
                else{
                    temp->next = temp1;
                    temp = temp->next;
                }
                temp1 = temp1->next;
            }
            else if(temp1->val >= temp2->val)
            {
                if(!head){
                    head = temp2;
                    temp = temp2;
                }
                else{
                    temp->next = temp2;
                    temp = temp->next;
                }
                temp2 = temp2->next;
            }
        }
        while(temp1){
            if(!head){
                head = temp1;
                temp = temp1;
            }
            else{
                temp->next = temp1;
                temp = temp->next;
            }
            temp1 = temp1->next;
        }
        while(temp2){
            if(!head){
                head = temp2;
                temp = temp2;
            }
            else{
                temp->next = temp2;
                temp = temp->next;
            }
            temp2 = temp2->next;
        }
        return head;
    }
};