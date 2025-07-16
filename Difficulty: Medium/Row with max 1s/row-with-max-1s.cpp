// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) 
    {
        int r=arr.size(), c=arr[0].size();
        int i=0, j=c-1,ans=-1;
        while(i<r && j>=0)
        {
            if(arr[i][j]==1){
                ans=i;
                j--;
            }
            else if(arr[i][j]==0){
                i++;
            }
        }
        return ans;
    }
};