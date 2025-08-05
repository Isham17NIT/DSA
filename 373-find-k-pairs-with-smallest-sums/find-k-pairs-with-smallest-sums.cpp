class Solution 
{
private:
    struct Compare{
        vector<int>& arr1;
        vector<int>& arr2;
        Compare(vector<int>& nums1, vector<int>& nums2) : arr1(nums1), arr2(nums2) {}
        bool operator()(pair<int,int> &a, pair<int,int> &b)
        {
            return arr1[a.first]+arr2[a.second] > arr1[b.first]+arr2[b.second]; //min heap based on sum
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<vector<int>> ans;
        Compare comp(nums1, nums2);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq(comp);
        set<pair<int,int>> visited;
        pq.push({0,0});
        while(k--)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back({nums1[p.first], nums2[p.second]});
            if(p.first+1 < nums1.size() && visited.find({p.first+1, p.second})==visited.end()){
                pq.push({p.first+1, p.second});
                visited.insert({p.first+1, p.second});
            }                
            if(p.second+1 < nums2.size() && visited.find({p.first, p.second+1})==visited.end()){
                pq.push({p.first, p.second+1});
                visited.insert({p.first, p.second+1});
            }
        }
        return ans;
    }
};