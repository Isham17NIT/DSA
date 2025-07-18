class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int xor1 = 0;
        for(char c : s){
            xor1 ^= (c-'a');
        }
        for(char c : t){
            xor1 ^= (c-'a');
        }
        return xor1 + 'a';
    }
};