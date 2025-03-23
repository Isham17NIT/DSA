class Solution {
public:
    int findParent(vector<int> &parent,int x)
    {
        if(x==parent[x])
            return x;
        return parent[x] = findParent(parent,parent[x]);
    }
    void findUnion(int pu,int pv,vector<int>& parent,vector<int> &size)
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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int extra=0; //no. of extra cables
        int nC=0; //no. of components
        vector<int> parent(n);
        vector<int> size(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        for(vector<int> e : connections)
        {
            int u=e[0];
            int v=e[1];
            int pu=findParent(parent,u);
            int pv=findParent(parent,v);
            if(pu!=pv)
            {
                findUnion(pu,pv,parent,size);
            }
            else
            {
                extra++;
            }
        }
        //find number of connected components
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                nC++;
        }
        return (extra>=nC-1) ? nC-1 : -1;
    }
};