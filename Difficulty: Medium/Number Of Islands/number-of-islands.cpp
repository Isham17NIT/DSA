//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    private:
        bool isValid(int i,int j,int n,int m)
        {
            return i>=0 && i<n && j>=0 && j<m;
        }
    
    public:
  
        int rows[4]={-1,0,1,0};
        int cols[4]={0,1,0,-1};
        
        int findUltimateParent(vector<int> &parent,int x)
        {
            if(x==parent[x])
                return x;
            return parent[x] = findUltimateParent(parent,parent[x]);
        }
        vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
        {
            int cnt=0;
            int k=operators.size();
            
            vector<int> ans(k);
            
            vector<int> visited(n*m,0);
            
            vector<int> parent(n*m);
            for(int i=0;i<n*m;i++)
            {
                parent[i] = i;
            }
            
            for(int i=0;i<operators.size();i++)
            {
                int r = operators[i][0];
                int c = operators[i][1];
                int node = r*m + c;
                
                if(visited[node])
                    ans[i] = cnt;
                else
                {
                    visited[node]=1;
                    cnt++;
                    //check for adjacent neighbours
                    for(int j=0;j<4;j++)
                    {
                        int newRow = r + rows[j];
                        int newCol = c + cols[j];
                        int newNode = newRow * m + newCol;
                        
                        if(isValid(newRow,newCol,n,m) && visited[newNode])
                        {
                            int ul=findUltimateParent(parent,newNode);
                            int nodeUl = findUltimateParent(parent,node);
                            if(ul != nodeUl)
                            {
                                cnt-=1;
                                parent[nodeUl]=ul;
                            }
                        }
                    }
                    ans[i] = cnt;
                }
            }
            return ans;
        }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends