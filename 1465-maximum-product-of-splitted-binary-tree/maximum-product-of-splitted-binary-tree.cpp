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
private:
    int mod=1e9+7;
    long long maxProd=0;

    long long getSum(TreeNode* root)
    {
        if(!root)
            return 0;
        long long lSum = getSum(root->left);
        long long rSum = getSum(root->right);
        return lSum + rSum + root->val;
    }
    long long calculateMaxProduct(TreeNode* root, long long &totalSum)
    {
        if(!root)
            return 0;
        long long lSum = calculateMaxProduct(root->left, totalSum);
        long long rSum = calculateMaxProduct(root->right, totalSum);
        // try splitting left edge
        maxProd = max(maxProd, lSum * (totalSum-lSum));
        // try splitting right edge
        maxProd = max(maxProd, rSum * (totalSum-rSum));
        return lSum + rSum + root->val;
    }
public:
    int maxProduct(TreeNode* root) 
    {
        long long totalSum=getSum(root); //total sum of tree

        calculateMaxProduct(root, totalSum);
        return maxProd%mod;
    }
};