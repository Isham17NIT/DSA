class Solution 
{
public:
    struct Edge
    {
        int src, dest, wt;
        Edge(int s,int d,int w)
        {
            src=s;
            dest=d;
            wt=w;
        }
    };
    int findParent(int parent[],int x)
    {
        if(x==parent[x])
            return x;
        return parent[x] = findParent(parent,parent[x]);
    }
    void findUnion(int pu,int pv,int parent[],int size[])
    {
        int su = size[pu];
        int sv = size[pv];
        if(su < sv){
            parent[pu]=pv;
            size[pv]+=su;
        }
        else{
            parent[pv]=pu;
            size[pu]+=sv;
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        int cnt=0;
        int parent[n];
        int size[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=0;
        }
        vector<Edge> edges;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    int pi = findParent(parent,i);
                    int pj = findParent(parent,j);
                    if(pi != pj)
                        findUnion(pi,pj,parent,size);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            findParent(parent,i);
        }
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                cnt++;
        }
        return cnt;
    }
};