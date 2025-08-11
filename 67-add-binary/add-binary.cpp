class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i=a.length()-1, j=b.length()-1;
        int carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry==1)
        {
            int sum=carry;
            if(i>=0){
                sum+=(a[i]-'0');
                i--;
            }
            if(j>=0){
                sum+=(b[j]-'0');
                j--;
            }
            ans = char(sum%2 + 48) + ans;
            carry = sum > 1 ? 1 : 0;
        }
        return ans;
    }
};