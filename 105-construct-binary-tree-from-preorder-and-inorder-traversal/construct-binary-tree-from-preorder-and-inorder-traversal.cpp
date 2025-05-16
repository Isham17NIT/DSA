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
    TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int,int> &m,
                        int preStart, int preEnd, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        int inRoot = m[preorder[preStart]]; //location of root in inorder traversal
        TreeNode* root = new TreeNode(inorder[inRoot]);

        int numsLeft = inRoot-inStart; //no. of elements on left of root in inorder traversal
        root->left = makeTree(preorder, inorder, m, preStart+1, preStart+numsLeft, inStart, inRoot-1);
        root->right = makeTree(preorder, inorder, m, preStart+numsLeft+1, preEnd, inRoot+1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]] = i;
        }
        TreeNode* root = makeTree(preorder, inorder, m, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};