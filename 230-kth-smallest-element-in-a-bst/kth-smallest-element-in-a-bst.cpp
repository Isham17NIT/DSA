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
    void findKthSmallestElement(TreeNode* root,int &k,int &ans)
    {
        if(root){
            findKthSmallestElement(root->left,k,ans);
            k-=1;
            if(k==0){
                ans = root->val;
                return;
            }
            findKthSmallestElement(root->right,k,ans);
        }
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = -1;
        findKthSmallestElement(root,k,ans);
        return ans;
    }
};