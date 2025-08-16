class Solution {
public:
    int maximum69Number (int num) 
    {
        int ans=0;
        vector<int> digits;
        bool replaced=false;
        while(num)
        {
            int digit=num%10;
            digits.push_back(digit);
            num/=10;
        }
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(!replaced && digits[i]==6){
                digits[i]=9;
                replaced=true;
            }
            ans = ans*10 + digits[i];
        }
        return ans;
    }
};