// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) 
    {
        int n=arr.size(), i=0, j=n-1;
        while(i<j)
        {
            while(i<j && arr[i]==0)
                i++;
            while(i<j && arr[j]==1)
                j--;
            if(i<j) //swap
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
            }
        }
        
    }
};