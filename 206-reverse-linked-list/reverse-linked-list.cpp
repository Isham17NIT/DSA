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
    ListNode* LLreverse(ListNode* prev, ListNode* curr, ListNode* temp)
    {
        if(!curr->next){
            curr->next = prev;
            return curr;
        }
        curr->next = prev;
        return LLreverse(curr, temp, temp->next);
    }
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* prev = nullptr, *curr = head, *temp = head->next;
        return LLreverse(prev, curr, temp);
    }
};