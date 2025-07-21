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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp1=l1, *temp2=l2;
        ListNode* ans=nullptr; 
        ListNode* temp=nullptr;
        int carry = 0;
        while(temp1 || temp2)
        {
            int sum = 0;
            if(temp1)
                sum+=temp1->val;
            if(temp2)
                sum+=temp2->val;
            sum+=carry;
            carry=sum/10;
            sum=sum%10;                         
            if(!ans){
                ans = new ListNode(sum);
                temp = ans;
            }
            else{
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            if(temp1)
                temp1=temp1->next;
            if(temp2)
                temp2=temp2->next;
        }
        if(carry!=0)
        {
            temp->next = new ListNode(carry);
        }
        return ans;
    }
};