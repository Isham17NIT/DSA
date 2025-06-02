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
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(!root)
            return;
        stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();
            s.pop();
            if(prev)
            {
                prev->right=root;
                prev->left=nullptr;
            }
            prev=root;
            if(root->right)
                s.push(root->right);
            if(root->left)
                s.push(root->left);
        }
        root=prev;
        return;
    }
};