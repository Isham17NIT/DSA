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
    int findMaxIndex(vector<int> nums,int start,int end)
    {
        int maxIdx = start;
        for(int i=start+1;i<=end;i++)
        {
            if(nums[i] > nums[maxIdx])
                maxIdx = i;
        }
        return maxIdx;
    }
    TreeNode* createMaxBinaryTree(vector<int> nums,int start, int end)
    {
        if(start > end)
            return nullptr;
        int maxIdx = findMaxIndex(nums,start,end);

        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = createMaxBinaryTree(nums,start, maxIdx-1);
        root->right = createMaxBinaryTree(nums,maxIdx+1, end);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        TreeNode* root = nullptr;
        return createMaxBinaryTree(nums,0,nums.size()-1);
    }
};