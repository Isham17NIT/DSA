class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(char c : ransomNote){
            freq1[c-'a']+=1;
        }
        for(char c : magazine){
            freq2[c-'a']+=1;
        }
        for(int i=0;i<26;i++)
        {
            if(freq1[i] > freq2[i])
                return false;
        }
        return true;
    }
};