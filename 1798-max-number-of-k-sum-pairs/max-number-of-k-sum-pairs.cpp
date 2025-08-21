class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int cnt=0;
        unordered_map<int,int> m;
        for(int i : nums)
        {
            if(m.find(k-i)!=m.end()){
                m[k-i]-=1;
                cnt++;
                if(m[k-i]==0)
                    m.erase(k-i);
            }
            else
                m[i]+=1;                
        }
        return cnt;
    }
};