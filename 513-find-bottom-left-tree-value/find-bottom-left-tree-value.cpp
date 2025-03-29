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
    bool isLeaf(TreeNode* root)
    {
        return !root->left && !root->right;
    }
    void levelOrderTraversal(TreeNode* root,int &ans)
    {
        queue<TreeNode*> q;
        q.push(root);

        int cnt=1; //no. of nodes in current level
        int child=0; //no. of nodes in next level

        while(!q.empty())
        {
            ans = q.front()->val; //update the value to the first value at each level

            while(cnt > 0)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                {
                    child++;
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    child++;
                    q.push(curr->right);
                }
                cnt--;
            }
            cnt = child;
            child = 0;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) 
    {
        if(isLeaf(root))
            return root->val;
        
        //ans will be the first value in the last level of level order traversal
        int ans=0;
        levelOrderTraversal(root, ans);
        return ans;
    }
};