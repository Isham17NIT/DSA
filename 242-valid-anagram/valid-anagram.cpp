class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        vector<int> freq(26,0);
        for(char c : s)
        {
            freq[c-'a']+=1;
        }
        for(char c : t){
            freq[c-'a']-=1;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                return false;
        }
        return true;
    }
};