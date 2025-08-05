class Solution 
{
private:
    struct Compare{
        bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b)
        {
            return a.first > b.first; //min heap based on sum
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare> pq;
        set<pair<int,int>> visited;
        pq.push({nums1[0]+nums2[0],{0,0}});
        while(k--)
        {
            pair<int,int> p=pq.top().second;
            pq.pop();
            ans.push_back({nums1[p.first], nums2[p.second]});
            if(p.first+1 < nums1.size() && visited.find({p.first+1, p.second})==visited.end()){
                int sum=nums1[p.first+1]+nums2[p.second];
                pq.push({sum,{p.first+1, p.second}});
                visited.insert({p.first+1, p.second});
            }                
            if(p.second+1 < nums2.size() && visited.find({p.first, p.second+1})==visited.end()){
                int sum=nums1[p.first]+nums2[p.second+1];
                pq.push({sum,{p.first, p.second+1}});
                visited.insert({p.first, p.second+1});
            }
        }
        return ans;
    }
};