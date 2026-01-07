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
    long long inorderTraversal(TreeNode* root, vector<long long> &subtreeSums)
    {
        if(!root)
            return 0;
        long long subTreeSum = root->val + inorderTraversal(root->left, subtreeSums) + inorderTraversal(root->right, subtreeSums);
        subtreeSums.push_back(subTreeSum);
        return subTreeSum;
    }
public:
    int maxProduct(TreeNode* root) 
    {
        vector<long long> subtreeSums;
        long long maxProd=0;
        int mod=1e9+7;
        long long totalSum = inorderTraversal(root, subtreeSums);
        for(long long i=0;i<subtreeSums.size()-1;i++)
        {
            // try cutting the edge above this subtree
            long long s = subtreeSums[i];
            maxProd = max(maxProd, s * (totalSum-s));
        }
        return maxProd%mod;
    }
};