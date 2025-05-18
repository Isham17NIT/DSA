//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution 
{
    Node* findMiddleNode(Node* head)
    {
        if(!head || head->next==NULL)
            return head;
        Node* slow=head;
        Node* fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* head1, Node* head2)
    {
        Node* head=NULL, *temp=NULL;
        while(head1 && head2)
        {
            if(head1->data <= head2->data)
            {
                if(!head)
                {
                    head=head1;
                    temp=head;
                }
                else
                {
                    temp->next=head1;
                    temp=temp->next;
                }
                head1=head1->next;
            }
            else
            {
                if(!head)
                {
                    head=head2;
                    temp=head;
                }
                else
                {
                    temp->next=head2;
                    temp=temp->next;
                }
                head2=head2->next;
            }
        }
        while(head1)
        {
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
        }
        while(head2)
        {
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
        temp->next=nullptr;
        return head;
    }
    Node* mergeSortAux(Node* head1)
    {
        if(!head1 || !head1->next)
            return head1;
        Node* middle = findMiddleNode(head1);
        Node* head2 = middle->next;
        
        middle->next=nullptr;
        
        head1 = mergeSortAux(head1);
        head2 = mergeSortAux(head2);
        return merge(head1,head2);
    }
  public:
    Node* mergeSort(Node* head) 
    {
       return mergeSortAux(head);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends