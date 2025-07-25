/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    vector<int> traversal;
    int ptr;
private:
    void inorderTraversal(TreeNode* root, vector<int> &traversal)
    {
        if(root){
            inorderTraversal(root->left, traversal);
            traversal.push_back(root->val);
            inorderTraversal(root->right, traversal);
        }
        return;
    }
public:
    BSTIterator(TreeNode* root) 
    {
        traversal = vector<int>();
        ptr=0;
        inorderTraversal(root, traversal);
    }
    
    int next() 
    {
        return traversal[ptr++];
    }
    
    bool hasNext() {
        return ptr < traversal.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */