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
class Solution 
{
public:
    int maxDia = 0;
    int findHeight(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1 + max(lh, rh);
    }
    void inorderTraversal(TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorderTraversal(root->left);

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        maxDia = max(maxDia, lh + rh);

        inorderTraversal(root->right);
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        inorderTraversal(root);
        return maxDia;
    }
};