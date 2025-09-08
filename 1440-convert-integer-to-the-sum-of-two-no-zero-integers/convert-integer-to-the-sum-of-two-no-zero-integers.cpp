class Solution {
private:
    bool isNoZero(int i)
    {
        int temp=i;
        while(temp)
        {
            int digit=temp%10;
            if(digit==0)
                return false;
            temp/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) 
    {
        int low=1, high=n-1;
        vector<int> ans;
        while(low<=high)
        {
            if(isNoZero(low) && isNoZero(high))
            {
                ans.push_back(low);
                ans.push_back(high);
                break;
            }
            low++;
            high--;
        }
        return ans;
    }
};