class Solution 
{
private:
    string generateString(vector<string> &mat)
    {
        string ans="";
        for(string i : mat)
        {
            ans+=i;
        }
        return ans;
    }
public:
    string convert(string s, int numRows) 
    {
        int n=s.length();
        if(numRows==1 || numRows>=n)
            return s;

        vector<string> mat(numRows, "");
        int i=0, step=1; 
        for(int k=0;k<s.length();k++)
        {
            mat[i]+=s[k];
            if(i==numRows-1)
                step=-1;
            else if(i==0)
                step=1;
            i+=step;
        }
        return generateString(mat);
    }
};