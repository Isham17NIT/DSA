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
    TreeNode* buildTheTree(vector<int>  &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int idx = -1;
        for(int i=inStart;i<=inEnd;i++)
        {
            if(inorder[i]==preorder[preStart]){
                idx = i;
                break;
            }
        }
        int nodes = idx-inStart;
        root->left = buildTheTree(preorder, inorder, preStart+1, preStart+nodes,inStart, idx-1);
        root->right = buildTheTree(preorder, inorder, preStart+nodes+1, preEnd,idx+1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTheTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
