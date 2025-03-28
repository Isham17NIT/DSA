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
    int findMaxDia(TreeNode* root, int &maxDia)
    {
        if(root==nullptr)
            return 0;
        int lh = findMaxDia(root->left, maxDia);
        int rh = findMaxDia(root->right, maxDia);
        maxDia = max(maxDia, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxDia=0;
        findMaxDia(root, maxDia);
        return maxDia;
    }
};