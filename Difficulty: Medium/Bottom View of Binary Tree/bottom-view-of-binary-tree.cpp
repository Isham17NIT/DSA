//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends


class Solution 
{
  public:
    void levelOrderTraversal(Node* root, map<int,int> &m)
    {
        queue<pair<Node*, int>> q; //node : col
        q.push({root,0});
        
        int cnt = 1; //count of nodes in current level
        int child = 0; //count of nodes in next level
        
        while(!q.empty())
        {
            while(cnt > 0)
            {
                pair<Node*,int> curr = q.front();
                q.pop();
                
                m[curr.second] = curr.first->data;
                if(curr.first->left)
                {
                    child++;
                    q.push({curr.first->left,curr.second - 1});
                }
                if(curr.first->right)
                {
                    child++;
                    q.push({curr.first->right,curr.second + 1});
                }
                cnt--;
            }
            cnt = child;
            child = 0;
        }
        return;
    }
    vector <int> bottomView(Node* root) 
    {
        vector<int> ans;
        if(!root)
            return ans;
            
        map<int, int> m; // col_number : last element in that column 
        
        levelOrderTraversal(root, m);
        
        for(auto &it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends