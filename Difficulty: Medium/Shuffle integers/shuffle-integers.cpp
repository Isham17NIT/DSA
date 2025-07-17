class Solution {

  public:
    void shuffleArray(int arr[], int n) 
    {
        if(n < 3)   
            return;
        int i=1, j=n/2;
        for(int j=n/2;j<n-1;j++)
        {
            int el = arr[j];
            for(int k=j-1;k>=i;k--)
            {
                arr[k+1]=arr[k];
            }
            arr[i] = el;
            i+=2;
        }
    }
};