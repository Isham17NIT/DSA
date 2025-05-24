/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) 
    {
        if(!root)
            return 1;
        else if(!root->left && !root->right)
            return 1;
        if(root->left && root->right)
        {
            if(root->data == root->left->data + root->right->data)
            {
                return isSumProperty(root->left) && isSumProperty(root->right);
            }
        }
        else if(root->left && root->data == root->left->data)
        {
            return isSumProperty(root->left);
        }
        else if(root->right && root->data == root->right->data)
        {
            return isSumProperty(root->right);
        }
        return 0;
    }
};






