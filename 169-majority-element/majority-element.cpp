class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int el, cnt=0;
        for(int i : nums)
        {
            if(cnt==0)
            {
                el=i;
                cnt=1;
            }
            else if(i==el)
                cnt++;
            else
                cnt--;
        }
        return el;
    }
};