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
    struct Qnode
    {
        TreeNode* root;
        int row, col;
        Qnode(TreeNode* r, int i, int j)
        {
            root=r;
            row=i;
            col=j;
        }
    };
    void levelOrderTraversal(TreeNode* root,map<int,vector<pair<int,int>>> &m)
    {
        queue<Qnode> q; //will store node, col no. of node
        q.push(Qnode(root,0,0));
        int cnt=1; //count of nodes in current level
        int child=0; //count of nodes in next level
        while(!q.empty())
        {
            while(cnt > 0)
            {
                Qnode curr = q.front();
                m[curr.col].push_back({curr.row, curr.root->val}); //insert into map at specified column
                q.pop();
                if(curr.root->left)
                {
                    child++;
                    q.push(Qnode(curr.root->left, curr.row + 1,curr.col - 1));
                }
                if(curr.root->right)
                {
                    child++;
                    q.push(Qnode(curr.root->right, curr.row + 1,curr.col + 1));
                }
                cnt--;
            }
            cnt = child;
            child=0;
        }
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,vector<pair<int,int>>> m; // col : [[rowNo, element],[rowNo, element]]
        levelOrderTraversal(root,m);
        vector<vector<int>> ans;
        for(auto &it : m)
        {
            if(!it.second.empty())
            {
                sort(it.second.begin(),it.second.end()); //by default sorting first based on row no. and then based on col no.
                vector<int> curr;
                for(pair<int,int> p : it.second)
                {
                    curr.push_back(p.second);
                }
                ans.push_back(curr);
            }
        }
        return ans;
    }
};