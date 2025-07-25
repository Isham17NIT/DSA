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
private:
    int findMaxSum(TreeNode* root,int &maxSum)
    {
        if(!root)
            return 0;
        int lSum = findMaxSum(root->left, maxSum);
        int rSum = findMaxSum(root->right, maxSum);
        lSum = lSum < 0 ? 0 : lSum;
        rSum = rSum < 0 ? 0 : rSum;
        maxSum = max(maxSum, lSum+rSum+root->val);
        return root->val + max(lSum, rSum);
    }
public:
    int maxPathSum(TreeNode* root) 
    {
        int maxSum = INT_MIN;
        findMaxSum(root, maxSum);
        return maxSum;
    }
};