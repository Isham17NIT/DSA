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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=1;
        int child=0;
        while(!q.empty())
        {
            vector<int> currLevel;
            while(cnt > 0)
            {
                TreeNode* curr = q.front();
                currLevel.push_back(curr->val);
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    child++;
                }
                if(curr->right){
                    q.push(curr->right);
                    child++;
                }
                cnt--;
            }
            cnt = child;
            child = 0;
            ans.push_back(currLevel);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};