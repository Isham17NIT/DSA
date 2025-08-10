class Solution 
{
private:
    void findAllCombos(int idx,string &digits,string curr,vector<string> &ans,unordered_map<int,string> &mappings)
    {
        if(idx==digits.length())
        {
            ans.push_back(curr);
            return;
        }
        string s = mappings[digits[idx]-'0'];
        for(int i=0;i<s.length();i++)
        {
            findAllCombos(idx+1,digits,curr+s[i],ans,mappings);
        }
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if(digits=="")
            return ans;
        unordered_map<int,string> mappings = {{2,"abc"}, {3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        findAllCombos(0,digits,"",ans,mappings);
        return ans;
    }
};