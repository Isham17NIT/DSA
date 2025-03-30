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
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(!root)
            return ans;

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            if(s.top()->left)
            {
                s.push(s.top()->left);
            }
            else
            {
                TreeNode* curr = s.top();
                while(!curr->right)
                {
                    ans.push_back(curr->val);
                    s.pop();
                    if(s.empty())
                        break;
                    curr = s.top();
                }
                if(!s.empty())
                {
                    ans.push_back(curr->val);
                    s.pop();
                    s.push(curr->right);
                }
            }
        }
        return ans;
    }
};