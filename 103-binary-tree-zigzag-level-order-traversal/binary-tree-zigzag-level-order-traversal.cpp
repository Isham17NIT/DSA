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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        bool flag=true;
        int cnt=1; //count of nodes in current level
        int child=0; //count of nodes in next level
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> currLevel;
            while(cnt > 0)
            {
                TreeNode* curr = q.front();
                currLevel.push_back(curr->val);
                q.pop();

                if(curr->left){
                    child++;
                    q.push(curr->left);
                }
                if(curr->right){
                    child++;
                    q.push(curr->right);
                }
                cnt--;
            }
            cnt = child;
            child = 0;
            if(!flag)
            {
                reverse(currLevel.begin(),currLevel.end());
            }  
            ans.push_back(currLevel);
            flag = !flag;
        }
        return ans;
    }
};