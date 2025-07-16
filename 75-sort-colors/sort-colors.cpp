class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0){
                nums[mid] = nums[low];
                nums[low] = 0;
                mid++; low++;
            }
            else if(nums[mid]==1){
                //already at its correct posn
                mid++;
            }
            else if(nums[mid]==2){
                nums[mid] = nums[high];
                nums[high] = 2;
                high--;
            }
        }
        return;
    }
};