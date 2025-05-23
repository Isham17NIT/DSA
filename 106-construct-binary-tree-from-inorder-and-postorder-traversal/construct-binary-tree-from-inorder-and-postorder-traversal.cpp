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
    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int> &mpp)
    {
        if(inStart > inEnd || postStart > postEnd)
            return nullptr;
        TreeNode* node = new TreeNode(postorder[postEnd]);
        int inroot = mpp[postorder[postEnd]]; //index of current node in inorder array
        int numRight = inEnd - inroot; //no. of elements of right of root in inorder traversal
        node->left = makeTree(inorder, postorder, inStart, inroot-1, postStart, postEnd-numRight-1, mpp);
        node->right = makeTree(inorder, postorder, inroot+1, inEnd, postEnd - numRight, postEnd-1, mpp);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return makeTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, mpp);
    }
};