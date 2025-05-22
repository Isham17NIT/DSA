class Solution {
  private:
    void merge(vector<int> &arr, int start, int mid, int end, int &cnt)
    {
        int n1=mid-start+1;
        int n2=end-mid;
        
        vector<int> leftSublist(n1+1);
        vector<int> rightSublist(n2+1);
        
        leftSublist[n1]=INT_MAX;
        rightSublist[n2]=INT_MAX;
        
        for(int i=start;i<=mid;i++)
        {
            leftSublist[i-start]=arr[i];
        }
        for(int j=mid+1;j<=end;j++)
        {
            rightSublist[j-mid-1]=arr[j];
        }
        
        int i=0, j=0;
        for(int k=start;k<=end;k++)
        {
            if(leftSublist[i]<=rightSublist[j])
            {
                arr[k]=leftSublist[i++];
            }
            else
            {
                arr[k]=rightSublist[j++];
                if(i!=n1)
                    cnt+=(n1-i);
            }
        }
        return;
    }
    void mergeSort(vector<int> &arr,int start,int end,int &cnt)
    {
        if(start<end)
        {
            int mid=(start+end)/2;
            mergeSort(arr, start, mid, cnt);
            mergeSort(arr, mid+1, end, cnt);
            merge(arr, start, mid, end, cnt);
        }
        return;
    }
  public:
    int inversionCount(vector<int> &arr) 
    {
        int cnt = 0;
        mergeSort(arr,0,arr.size()-1,cnt);
        return cnt;
    }
};