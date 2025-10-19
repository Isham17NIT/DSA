class Solution {
private:
    struct GraphNode{
        int val;
        vector<GraphNode*> children;
        bool visited;
        int d; //distance
        GraphNode(int val_)
        {
            val=val_;
            children=vector<GraphNode*>();
            visited=false;
            d=0;
        }
    };
    GraphNode* createGraph(TreeNode* root, TreeNode* target, GraphNode* &targetNode)
    {
        if(!root)
            return nullptr;

        GraphNode* lc=createGraph(root->left, target, targetNode);
        GraphNode* rc=createGraph(root->right, target, targetNode);

        GraphNode* g=new GraphNode(root->val);
        if(lc){
            //edges must be undirected
            g->children.push_back(lc);
            lc->children.push_back(g);
        }
        if(rc){
            //edges must be undirected
            g->children.push_back(rc);
            rc->children.push_back(g); 
        }
        if(root==target)
            targetNode=g;
        return g;
    }
    vector<int> bfs(GraphNode* node,int k)
    {
        vector<int> ans;
        if(!node)
            return ans;
        queue<GraphNode*> q;
        q.push(node);
        node->visited=true;
        while(!q.empty())
        {
            GraphNode* curr=q.front();
            q.pop();
            if(curr->d==k)
            {
                ans.push_back(curr->val);
                continue;
            }
            for(GraphNode* child:curr->children)
            {
                if(!child->visited)
                {
                    child->visited=true;
                    child->d=curr->d+1;
                    q.push(child);
                }
            }
        }
        return ans;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        GraphNode* targetNode=nullptr;
        createGraph(root, target,targetNode);
        vector<int> ans=bfs(targetNode,k);
        return ans;
    }
};