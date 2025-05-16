//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;    // Value of the node
    Node* left;  // Pointer to the left child
    Node* right; // Pointer to the right child
};

// Function to create a new node with the given value
Node* createNewNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the binary tree from a string input
Node* buildTree(const string& str) {
    // Corner Case: if the input string is empty or starts with 'N', return NULL
    if (str.empty() || str[0] == 'N')
        return NULL;

    // Create a vector of strings from the input by splitting it on spaces
    vector<string> nodeValues;
    istringstream iss(str);
    for (string value; iss >> value;) {
        nodeValues.push_back(value);
    }

    // Create the root node of the tree
    Node* root = createNewNode(stoi(nodeValues[0]));

    // Use a queue to build the tree level by level
    queue<Node*> q;
    q.push(root);

    int i = 1; // Index for traversing the node values
    while (!q.empty() && i < nodeValues.size()) {
        Node* currentNode = q.front();
        q.pop();

        // Handle the left child
        string currentValue = nodeValues[i];
        if (currentValue != "N") {
            currentNode->left = createNewNode(stoi(currentValue));
            q.push(currentNode->left);
        }

        // Handle the right child
        i++;
        if (i >= nodeValues.size())
            break;
        currentValue = nodeValues[i];
        if (currentValue != "N") {
            currentNode->right = createNewNode(stoi(currentValue));
            q.push(currentNode->right);
        }
        i++;
    }

    return root;
}

// In-order traversal function to print the tree nodes
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


// } Driver Code Ends

/*
Structre of the node of the tree is as
struct Node
{
    int data;
    Node* left, *right;
};
*/
class Solution 
{
  public:
    Node* deleteNode(Node* root, int key) 
    {
        queue<pair<Node*, Node*>> q; //node:parent
        q.push({root, nullptr});
        
        Node* node = nullptr; //node to be found out
        Node* temp = nullptr; //deepest node's in binary tree
        Node* parent = nullptr; //deepest node's parent in binary tree
        
        while(!q.empty())
        {
            temp = q.front().first;
            parent = q.front().second;
            q.pop();
            if(temp->data == key)
                node = temp;
            
            if(temp->left)
                q.push({temp->left,temp});
            if(temp->right)
                q.push({temp->right,temp});
        }
        if(node!=nullptr) //node to be deleted is found in tree
        {
            node->data = temp->data;
            temp->data = key; 
            if(parent->left == temp)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        
        return root;
    }
};


//{ Driver Code Starts.

// Main function
int main() {
    int t;
    scanf("%d", &t); // Input the number of test cases

    while (t--) {
        int key;

        string input;
        getline(cin >> ws, input); // Read the input tree as a string
        scanf("%d", &key);         // Input the key to be deleted

        // Build the tree from the input string
        Node* root = buildTree(input);

        // Call the solution to delete the node with the given key
        Solution sol;
        root = sol.deleteNode(root, key);

        // Perform in-order traversal to display the tree
        inorderTraversal(root);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends