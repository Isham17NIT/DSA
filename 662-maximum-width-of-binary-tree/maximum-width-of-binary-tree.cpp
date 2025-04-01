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
    int widthOfBinaryTree(TreeNode* root) 
    {
        long long maxWidth=0;

        queue<pair<TreeNode*,long long>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            long long size = q.size(); //count o nodes at current level

            long long first = q.front().second;
            long long last = first;

            for(int i=0;i<size;i++)
            {
                pair<TreeNode*,int> curr = q.front();
                q.pop();        
                 //posn of first node at the current level
                last = curr.second - first;
                if(curr.first->left)
                {
                    q.push({curr.first->left, last*2 + 1});
                }
                if(curr.first->right)
                {
                    q.push({curr.first->right, last*2 + 2});
                }
            }
            maxWidth = max(maxWidth, last+1);   
        }
        return maxWidth;
    }
};