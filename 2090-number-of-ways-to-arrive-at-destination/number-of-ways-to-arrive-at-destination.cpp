class Solution 
{
private:
    struct Compare
    {
        bool operator()(pair<long long,int> &p1, pair<long long,int> &p2)
        {
            return p1.first > p2.first; //lesser distance has more priority
        }
    };
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        for(vector<int> v : roads)
        {
            graph[v[0]].push_back({v[1],v[2]});
            graph[v[1]].push_back({v[0],v[2]});
        }
        int mod = (int)(1e9 + 7);
        vector<int> ways(n,0);
        vector<long long> dist(n,LLONG_MAX);
        ways[0]=1;
        dist[0]=0;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,Compare> pq; //{dist, node}
        pq.push({0,0});

        while(!pq.empty())
        {
            pair<long long,int> curr = pq.top();
            pq.pop();
            int node = curr.second;
            for(pair<int,int> p : graph[node])
            {
                int neighbor = p.first;
                if(dist[neighbor] > curr.first + p.second)
                {
                    dist[neighbor] = curr.first + p.second;
                    ways[neighbor] = ways[node];
                    pq.push({dist[neighbor],neighbor});
                }
                else if(dist[neighbor] == curr.first + p.second)
                {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};