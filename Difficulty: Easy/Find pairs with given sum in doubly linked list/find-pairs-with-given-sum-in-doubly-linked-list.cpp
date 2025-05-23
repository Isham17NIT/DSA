// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) 
    {
        vector<pair<int,int>> ans;
        if(head->next==NULL)
            return ans;
        Node* tail = head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        Node* temp1 = head, *temp2 = tail;
        while(temp1 && temp2 && temp1!=temp2 && temp1->prev!=temp2)
        {
            int sum = temp1->data + temp2->data;
            if(sum==target)
            {
                ans.push_back({temp1->data, temp2->data});
                temp1=temp1->next;
                temp2=temp2->prev;
            }
            else if(sum<target)
                temp1=temp1->next;
            else
                temp2=temp2->prev;
        }
        return ans;
    }
};