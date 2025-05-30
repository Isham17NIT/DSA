//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution 
{
  private:
    void inorderTraversal(Node* root, int col, unordered_map<int,int> &m, int &min_col, int &max_col)
    {
        if(root)
        {
            inorderTraversal(root->left, col-1, m, min_col, max_col);
            m[col] += root->data;
            min_col = min(min_col, col);
            max_col = max(max_col, col);
            inorderTraversal(root->right, col+1, m, min_col, max_col);
        }
        return;
    }
  public:
    vector<int> verticalSum(Node *root) 
    {
        vector<int> ans;
        unordered_map<int,int> m; //col no. : sum
        int min_col = 0, max_col = 0;
        inorderTraversal(root, 0, m, min_col, max_col);
        for(int i=min_col; i<=max_col; i++)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{
    
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends