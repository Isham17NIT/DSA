class Solution {
private:
    int findLB(vector<int>& potions, int spell, long long success)
    {
        int low=0, high=potions.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if((long long)spell*(long long)potions[mid]>=success)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        if(ans==-1)
            return 0;
        return potions.size() - ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int n=spells.size();
        vector<int> pairs(n,0);
        sort(potions.begin(),potions.end());

        for(int i=0;i<n;i++)
        {
            pairs[i]=findLB(potions, spells[i], success); //find lower bound
        }
        return pairs;
    }
};