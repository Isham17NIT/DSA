class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) 
    {
        int n=arr.size(), ans=0;
        vector<int> leftMins(n); //index of minm element on left side
        vector<int> rightMaxs(n); //index of maxm element on right side
        leftMins[0] = 0; 
        rightMaxs[n-1] = n-1;
        int minm = arr[0], maxm = arr[n-1];
        for(int i=1;i<n;i++)
        {
            if(minm > arr[i]){
                minm = arr[i];
                leftMins[i] = i;
            }
            else
                leftMins[i] = leftMins[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(maxm < arr[i]){
                maxm = arr[i];
                rightMaxs[i] = i;
            }
            else
                rightMaxs[i] = rightMaxs[i+1];
        }
        int i=0, j=0;
        while(i<n && j<n)
        {
            if(arr[leftMins[i]] <= arr[rightMaxs[j]]){
                ans = max(ans, rightMaxs[j]-leftMins[i]);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};