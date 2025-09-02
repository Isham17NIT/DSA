class Solution {
  private:
    vector<int> merge(vector<int> &leftVal, vector<int> &rightVal)
    {
        return {min(leftVal[0], rightVal[0]), max(leftVal[1], rightVal[1])};
    }
    void updateHelper(int start,int end,int node,vector<int> &arr,int idx,int value,vector<vector<int>>& segTree)
    {
        if(idx > end)
            return;
        if(start==end) // we reached at the idx
        {
            arr[idx]=value;
            segTree[node]={value, value};
            return;
        }
        int mid=(start+end)>>1;
        if(idx<=mid) //go left
            updateHelper(start,mid,node*2+1,arr,idx,value,segTree);
        else //go right
            updateHelper(mid+1,end,node*2+2,arr,idx,value,segTree);
            
        segTree[node]=merge(segTree[node*2+1], segTree[node*2+2]);
    }
    vector<int> findMinMax(int start,int end,int node,int L,int R,vector<int> &arr,vector<vector<int>>& segTree)
    {
        if(start > end || L > R) 
            return {INT_MAX, INT_MIN}; //return an empty vector
        if(start==L && end==R) //total overlapping
            return segTree[node];
            
        // partial overlapping
        int mid=(start+end)>>1;
        vector<int> leftMinMax=findMinMax(start,mid,node*2+1,L,min(mid,R),arr,segTree);
        vector<int> rightMinMax=findMinMax(mid+1,end,node*2+2,max(mid+1,L),R,arr,segTree);
         //combine results
        return {min(leftMinMax[0], rightMinMax[0]), max(leftMinMax[1], rightMinMax[1])};
    }
  public:
    // Returns a vector<int> of size 2 where:
    // [0] = minimum value in arr from index L to R (inclusive),
    // [1] = maximum value in arr from index L to R (inclusive).
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    
    
    vector<int> getMinMax(vector<int>& arr, int L, int R, vector<vector<int>>& segTree) 
    {
        return findMinMax(0,arr.size()-1,0,L,R,arr,segTree);
    }

    // Updates the value at arr[index] to 'value' and updates the segTree accordingly.
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    void updateValue(vector<int>& arr, int idx, int value,vector<vector<int>>& segTree) 
    {
        updateHelper(0,arr.size()-1,0,arr,idx,value,segTree);
    }
};