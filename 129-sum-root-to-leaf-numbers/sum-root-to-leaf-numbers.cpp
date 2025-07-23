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
    void getRootToLeafSum(TreeNode* root, int curr, int &ans)
    {
        if(!root)
            return;
        if(!root->left && !root->right) //leaf node
            ans += (curr*10 + root->val);
        getRootToLeafSum(root->left, curr*10 + root->val, ans);
        getRootToLeafSum(root->right, curr*10 + root->val, ans);  
    }
public:
    int sumNumbers(TreeNode* root) 
    {
        int ans=0;
        getRootToLeafSum(root,0,ans);
        return ans;
    }
};