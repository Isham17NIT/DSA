/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1!=temp2)
        {
            if(!temp1)
            {
                temp1 = headB;
                temp2=temp2->next;
            }
            else if(!temp2)
            {
                temp2 = headA;
                temp1=temp1->next;
            }
            else
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return temp1;
    }
};