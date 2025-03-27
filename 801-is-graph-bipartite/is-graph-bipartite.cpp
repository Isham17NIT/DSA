class Solution 
{
public:
    bool dfsVisit(int curr,int color,vector<vector<int>>& graph,vector<int> &colors)
    {
        colors[curr]=color;
        for(int i : graph[curr])
        {
            if(colors[i]==-1)
            {
                if(!dfsVisit(i,!color,graph,colors))
                    return false;
            }
            else if(colors[i]==color) //can't be bipartite graph
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int> colors(graph.size(),-1);
        //we can take 2 colors  ->0 and 1
        //bipartite graph can be colored using 2 colors with no adjacent vertices having the same color
        for(int i=0;i<graph.size();i++)
        {
            if(colors[i]==-1) //not visited yet
            {
                if(!dfsVisit(i,0,graph,colors))
                    return false;
            }
        }
        return true;
    }
};