// brute force
class Solution {
private:
    int findBreakpoint(vector<int> &nums)
    {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        return i;
    }
    int findJustLargerThanBreakpt(vector<int> &nums, int i)
    {
        int j=nums.size()-1;
        while(j>i && nums[j]<=nums[i])
        {
            j--;
        }
        return j;
    }
    void reverseArray(vector<int> &nums, int start)
    {
        int i=start, j=nums.size()-1;
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++; j--;
        }
    }
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i=findBreakpoint(nums);
        if(i==-1) //largest permutation--->descending order of elements
        {
            sort(nums.begin(),nums.end());
            return;
        }

        int j=findJustLargerThanBreakpt(nums, i);
        swap(nums[i],nums[j]);

        reverseArray(nums, i+1);
    }
};