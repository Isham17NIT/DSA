class Solution {
private:
    int findIdx(vector<int> &arr, int num)
    {
        int low=0, high=arr.size()-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(arr[mid]==num)
                return mid;
            else if(arr[mid]>num)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
public:
    int lengthOfLIS(vector<int>& infoUnits) 
    {
       vector<int> arr;
        arr.push_back(infoUnits[0]);
        
        for(int i=1;i<infoUnits.size();i++)
        {
            int idx = findIdx(arr, infoUnits[i]);
            if(idx == arr.size())
                arr.push_back(infoUnits[i]);
            else
                arr[idx] = infoUnits[i];
        }
        return arr.size(); 
    }
};