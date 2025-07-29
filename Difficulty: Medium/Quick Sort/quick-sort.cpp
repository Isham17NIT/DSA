class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high)
        {
            int pos = partition(arr, low, high);
            quickSort(arr, low, pos-1);
            quickSort(arr, pos+1, high);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        int pivot=arr[high];
        int i=low-1, j=0;
        for(int j=low;j<high;j++)
        {
            if(arr[j] < pivot){
                swap(arr[++i],arr[j]);//keep on appending to i-list
            }
        }
        //at last swap arr[i] and arr[high]
        swap(arr[i+1],arr[high]);
        return i+1;
    }
};