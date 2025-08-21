class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int nums1=INT_MAX, nums2=INT_MAX;
        for(int i : nums)
        {
            if(i<=nums1){
                nums1=i;
            }
            else if(i<=nums2){
                nums2=i;
            }
            else{
                //triplet found
                return true;
            }
        }
        return false;
    }
};