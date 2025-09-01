class NumArray 
{
private:
    vector<int> tree;
    int n;
    void buildTree(int start, int end, int node,vector<int> &nums, vector<int> &tree)
    {
        if(start==end){
            tree[node]=nums[start];
            return;
        }
        int mid=(start+end)>>1;
        //build left subtree
        buildTree(start, mid, node*2+1,nums, tree);
        //build right subtree
        buildTree(mid+1, end, node*2+2,nums, tree);
        tree[node]=tree[node*2+1] + tree[node*2+2];
    }
    int merge(int leftVal,int rightVal)
    {
        return leftVal+rightVal;
    }
    void updateHelper(int start,int end,int node,vector<int> &tree, int index,int val)
    {
        if(index>end || index<start) //out of range
            return;
        if(start==end) //leaf node--->means we reached at that index
        {
            tree[node]=val;
            return;
        }
        int mid=(start+end)>>1;
        if(mid>=index) //go left
            updateHelper(start,mid,node*2+1,tree,index,val);
        else //go right
            updateHelper(mid+1,end,node*2+2,tree,index,val);

        tree[node]=merge(tree[node*2+1],tree[node*2+2]);
    }
    int sumRangeHelper(int start,int end,int node,vector<int> &tree,int l,int r)
    {
        if(l>end || r<start || l>r) //no overlapping
            return 0;

        if(start==l && end==r) //total overlapping
            return tree[node];

        // partial overlapping
        int mid=(start+end)>>1;
        int lSum=sumRangeHelper(start,mid,node*2+1,tree,l,min(mid,r));
        int rSum=sumRangeHelper(mid+1,end,node*2+2,tree,max(mid+1,l),r);
        return lSum+rSum;
    }
public:
    NumArray(vector<int>& nums){
        n=nums.size();
        tree=vector<int>(n*4,INT_MIN);
        buildTree(0,n-1,0,nums,tree);
    }
    
    void update(int index, int val) 
    {
        updateHelper(0,n-1,0,tree,index,val);
    }
    
    int sumRange(int l, int r) {
        return sumRangeHelper(0,n-1,0,tree,l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */