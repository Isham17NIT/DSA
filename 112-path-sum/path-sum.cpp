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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return false;
        int remSum = targetSum - root->val;
        if(!root->left && !root->right)
            return remSum==0;
        int leftCheck = hasPathSum(root->left, remSum);
        int rightCheck = hasPathSum(root->right, remSum);
        return leftCheck || rightCheck;
    }
};