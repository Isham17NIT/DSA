

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> ans;
        ans.push_back(arr[n-1]); //always a leader
        
        int maxTillNow=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=maxTillNow)
                ans.push_back(arr[i]);
            maxTillNow = max(maxTillNow, arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};