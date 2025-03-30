/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    bool findPath(TreeNode* root, int x, vector<TreeNode*> &path)
    {
        if(!root)
            return false;
        path.push_back(root);
        if(root->val==x) //node found
            return true;
        if(findPath(root->left, x, path) || findPath(root->right, x, path))
            return true;

        // node found in left and right part-->backtrack
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> path1; //p
        vector<TreeNode*> path2; //q
        findPath(root, p->val, path1);
        findPath(root, q->val, path2);

        int n = min(path1.size(),path2.size()) - 1;
        TreeNode* lca=nullptr;

        while(n>=0)
        {
            if(path1[n] == path2[n])
            {
                lca = path1[n];
                break;
            }
            n--;
        }
        return lca;
    }
};