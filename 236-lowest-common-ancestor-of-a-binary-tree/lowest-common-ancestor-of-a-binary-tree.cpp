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
public:
    TreeNode* findLCA(TreeNode* root, int p,int q)
    {
        if(!root)
            return NULL;
        if(root->val == p || root->val == q)
            return root;
        
        TreeNode* l = findLCA(root->left, p, q);
        TreeNode* r = findLCA(root->right, p, q);
        if(!l)
            return r;
        if(!r)
            return l;
        return root;        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return findLCA(root, p->val, q->val);
    }
};