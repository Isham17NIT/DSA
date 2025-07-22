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
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* temp1=list1, *temp2=list2;
        while(temp1 && temp2)
        {
            if(temp1->val < temp2->val){
                tail->next = temp1;
                temp1 = temp1->next;
            }
            else{
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }
        tail->next = temp1!=nullptr ? temp1 : temp2;
        return dummy.next; //dummy is the real head
    }
};