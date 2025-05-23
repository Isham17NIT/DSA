class FindSumPairs {
private:
    int findFirst(vector<int> &nums, int remSum)
    {
        int low = 0, high = nums.size()-1, first=-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(nums[mid]==remSum)
            {
                first = mid;
                high = mid-1;
            }
            else if(nums[mid] < remSum)
                low = mid+1;
            else
                high=mid-1;
        }
        return first;
    }
    int findLast(vector<int> &nums, int remSum)
    {
        int low = 0, high = nums2.size()-1, last=-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(nums[mid]==remSum)
            {
                last = mid;
                low = mid+1;
            }
            else if(nums[mid] < remSum)
                low = mid+1;
            else
                high=mid-1;
        }
        return last;
    }
public:
    vector<int> nums1;
    vector<int> nums2;
    map<int,int> mpp; //freq count
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int i : nums2)
        {
            mpp[i]+=1;
        }
    }
    
    void add(int idx, int val)
    {
        mpp[nums2[idx]]-=1;
        nums2[idx]+=val;
        mpp[nums2[idx]]+=1;
        return;
    }
    
    int count(int tot) 
    {
        int cnt=0;
        for(int i=0;i<nums1.size();i++)
        {
            int remSum = tot-nums1[i];
            if(mpp.find(remSum)!=mpp.end())
                cnt += mpp[remSum];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */