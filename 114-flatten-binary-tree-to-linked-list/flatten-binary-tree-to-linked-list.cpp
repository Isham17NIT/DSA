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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* prev = nullptr;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();
            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);
            if(!prev){
                prev = curr;
                prev->right = nullptr;
            }
            else{
                prev->right = curr;
                prev = prev->right;
            }
            curr->left = nullptr;
        }
        return;
    }
};