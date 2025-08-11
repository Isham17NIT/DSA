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
        int i=0;
        bool dir=true; // true : U to D  
        for(int k=0;k<s.length();k++)
        {
            mat[i]+=s[k];
            if(dir) //up to down dir
            {
                if(i==numRows-1)
                {
                    i--;
                    dir=false;
                }
                else
                    i++;
            }
            else{
                if(i==0)
                {
                    i++;
                    dir=true;
                }
                else{
                    i--;
                }
            }
        }
        return generateString(mat);
    }
};