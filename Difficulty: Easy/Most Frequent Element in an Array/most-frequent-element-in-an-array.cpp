class Solution {
  public:
    int mostFreqEle(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int maxCount = 1, maxElem = arr[0], count = 1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                count = 1; //reset count
            }
            if(maxCount==count)
                maxElem = max(maxElem,arr[i]);
            else if(maxCount < count)
            {
                maxCount = count;
                maxElem = arr[i];
            }
        }
        return maxElem;
    }
};