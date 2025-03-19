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
#include <stack>
class Solution 
{
public:
    ListNode* find_middle(ListNode* start)
    {
        if(start==NULL || start->next==NULL)
            return start;
        ListNode* slow=start;
        ListNode* fast=start;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    int calculateTotalNodes(ListNode* start)
    {
        int cnt=0;
        ListNode* slow=start;
        ListNode* fast=start;
        while(fast!=NULL && fast->next!=NULL)
        {
            cnt+=1;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==NULL)
            return 2*cnt;
        return 2*cnt + 1;
    }
    bool isPalindrome(ListNode* start) 
    {
        ListNode* middle = find_middle(start);
        stack<int> s;
        ListNode* temp=start;
        while(temp!=middle)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        int totalNodes=calculateTotalNodes(start);
        if(totalNodes%2!=0)
        {
            s.push(temp->val);
        }
        while(temp!=NULL)
        {
            int x=s.top();
            s.pop();
            if(x!=temp->val)
                return false;
            temp=temp->next;
        }
        return true;
    }
};