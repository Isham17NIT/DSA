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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<TreeNode*> currLevel;
        unordered_map<TreeNode*, TreeNode*> m; // node : parent
        m[root]=nullptr;
        q.push(root);
        while(!q.empty())
        {
            currLevel.clear();
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                currLevel.push_back(curr);
                if(curr->left){
                    q.push(curr->left);
                    m[curr->left] = curr;
                }
                if(curr->right){
                    q.push(curr->right);
                    m[curr->right] = curr;
                }
            }
        }
        while(currLevel.size() > 1){
            vector<TreeNode*> next;
            int n=currLevel.size();
            for(int i=0;i<n;i++)
            {
                if(next.empty() || m[currLevel[i]] != next.back()){
                    next.push_back(m[currLevel[i]]);
                }
            }
            currLevel = next;
        }
        return currLevel[0];
    }
};