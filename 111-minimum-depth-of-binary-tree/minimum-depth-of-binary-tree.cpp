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
    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
            
        int ld = INT_MAX, rd = INT_MAX;
        if(root->left)
            ld = minDepth(root->left);
        if(root->right)
            rd = minDepth(root->right);

        return 1 + min(ld, rd);
    }
};