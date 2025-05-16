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
    TreeNode* constructBST(vector<int> &nums,int start, int end)
    {
        if(start> end)
            return nullptr;
        int rootIdx = (start+end)>>1;
        TreeNode* root = new TreeNode(nums[rootIdx]);
        root->left = constructBST(nums,start,rootIdx-1);
        root->right = constructBST(nums, rootIdx+1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return constructBST(nums,0,nums.size()-1);
    }
};