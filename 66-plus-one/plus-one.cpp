class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int i=digits.size()-1;
        while(i>=0 && digits[i] == 9)
        {
            digits[i]=0;
            i--;
        }
        if(i>=0)
            digits[i]+=1;
        else
        {
            vector<int> ans={1};
            ans.insert(ans.end(), digits.begin(), digits.end());
            return ans;
        }
        return digits;
    }
};