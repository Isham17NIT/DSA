class Solution {
public:
    int findUltimateParent(vector<int> &parent, int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=findUltimateParent(parent, parent[x]);
    }
    void unionBySize(int pu,int pv,vector<int> &parent,vector<int> &size)
    {
        int s1 = size[pu];
        int s2 = size[pv];
        if (size[pu] < size[pv]) 
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        } 
        else 
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int maxRow=0, maxCol=0;
        //find total no. of rows and cols
        for(vector<int> v : stones)
        {
            maxRow=max(maxRow,v[0]+1);
            maxCol=max(maxCol,v[1]+1);
        }

        vector<int> parent(maxRow+maxCol);
        vector<int> size(maxRow+maxCol,1);

        for(int i=0;i<maxRow+maxCol;i++)
        {
            parent[i]=i;
        }

        unordered_set<int> stoneNodes;
        for(vector<int> s : stones)
        {
            int u = s[0];
            int v = s[1] + maxRow;
            stoneNodes.insert(u);
            stoneNodes.insert(v);
            int pu = findUltimateParent(parent,u);
            int pv = findUltimateParent(parent,v);
            if(pu != pv)
            {
                unionBySize(pu,pv,parent,size);
            }
        }

        // now we have to find the no. of valid ultimate parents
        int cnt=0;
        for(int i : stoneNodes)
        {
            if(findUltimateParent(parent,i)==i)
                cnt++;
        }
        return stones.size()-cnt;
    }
};