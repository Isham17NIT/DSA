/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    bool getCopy(TreeNode* root1, TreeNode* root2, TreeNode* target, TreeNode* &ans)
    {
        if(!root1)
            return false;
        if(getCopy(root1->left, root2->left, target,ans))
            return true;
        if(root1==target){
            ans=root2;
            return true;
        }
        return getCopy(root1->right, root2->right, target,ans);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        getCopy(original, cloned, target, ans);
        return ans;
    }
};