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
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) 
    {
        s = stack<TreeNode*>();
        TreeNode* temp = root;
        while(temp)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() 
    {
        TreeNode* curr = s.top();
        s.pop();
        int ans = curr->val;
        if(curr->right) //push everything on its right onto the stack
        {
            curr = curr->right;
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */