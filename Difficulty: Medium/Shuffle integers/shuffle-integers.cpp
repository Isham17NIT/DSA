class Solution {

  public:
    void shuffleArray(int arr[], int n) 
    {
        for(int i=0;i<n/2;i++)
        {
            arr[i] = arr[i] | (arr[n/2 + i] << 10);
        }
        for(int i=n/2 - 1;i>=0;i--)
        {
            arr[i*2 + 1] = (arr[i] >> 10);
            arr[i*2] = (arr[i] & 1023);
        }
    }
};