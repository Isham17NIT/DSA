class Solution 
{
private:
    void findLexSmallestStringHelper(string str, int a, int b, set<string> &s)
    {
        if(s.find(str)!=s.end())
            return;
        // insert the curr string
        s.insert(str);
        //rotate
        string rotatedStr=str.substr(str.size()-b,b)+str.substr(0,str.size()-b);
        findLexSmallestStringHelper(rotatedStr, a, b, s);
        //add a
        string addedStr=str;
        for(int i=1;i<str.size();i+=2)
        {
            int currChar=str[i]-'0';
            addedStr[i]=((currChar+a)%10)+'0';
        }
        findLexSmallestStringHelper(addedStr, a, b, s);
        return;
    } 
public:
    string findLexSmallestString(string str, int a, int b) 
    {
        set<string> s;
        findLexSmallestStringHelper(str, a, b, s);
        auto it=s.begin();
        return *it;
    }
};