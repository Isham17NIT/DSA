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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool LtoR = true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> currLevel(n,0);
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(LtoR)
                    currLevel[i] = curr->val;
                else
                    currLevel[n-1-i] = curr->val;
                    
                if(curr->left)
                    q.push(curr->left);              
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(currLevel);
            LtoR = !LtoR;
        }
        return ans;
    }
};