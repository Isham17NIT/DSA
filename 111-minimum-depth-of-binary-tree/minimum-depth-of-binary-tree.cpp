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
    bool isLeaf(TreeNode* root)
    {
        return !root->left && !root->right;
    }
    int minDepth(TreeNode* root) // using level order traversal approach
    {
        if(!root)
            return 0;
        if(isLeaf(root))
            return 1;

        queue<TreeNode*> q;
        q.push(root);
        int cnt=1;
        int child=0; //count of nodes in next level
        int level = 0; // to keep track of current level
        while(!q.empty())
        {
            vector<int> currLevel;
            while(cnt > 0)
            {
                TreeNode* curr = q.front();
                currLevel.push_back(curr->val);
                q.pop();
                if(isLeaf(curr))
                    return level+1;
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
            level++;
        }
        return 0;
    }
};