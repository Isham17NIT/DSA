class Solution 
{
private:
    void appendRemaining(string s, int idx, string &ans, int carry)
    {
        for(int i=idx;i>=0;i--)
        {
            int sum = carry + (s[i]-'0');
            ans = char(sum%2 + 48) + ans;
            carry = sum > 1 ? 1 : 0;
        }
        if(carry==1)
            ans = '1' + ans;
    }
public:
    string addBinary(string a, string b) 
    {
        int l1=a.length(), l2=b.length();
        string ans="";
        int carry=0, i=0;
        for(i=0;i<min(l1,l2);i++)
        {
            int c1=a[l1-1-i]-'0';
            int c2=b[l2-1-i]-'0';
            int sum=c1+c2+carry;
            ans = char(sum%2 + 48) + ans;
            carry = sum > 1 ? 1 : 0;
        }
        if(l1 > l2)
            appendRemaining(a, l1-l2-1, ans, carry);
        else if(l1 < l2)
            appendRemaining(b, l2-l1-1, ans, carry);
        else{
            if(carry==1)
                ans='1'+ans;
        }
        return ans;
    }
};