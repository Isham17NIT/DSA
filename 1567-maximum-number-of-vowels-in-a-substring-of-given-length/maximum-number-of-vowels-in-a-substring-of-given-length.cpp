class Solution {
private:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    int maxVowels(string s, int k) 
    {
        unordered_map<int,int> m;
        int cnt=0, maxCnt=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                cnt++;
                m[s[i]]+=1;
            }
        }
        maxCnt=max(cnt, maxCnt);
        for(int i=k;i<s.length();i++)
        {
            int idx=i-k; //start of the prev window
            if(isVowel(s[idx])){
                cnt--;
                m[s[idx]]-=1;
            }
            if(isVowel(s[i])){
                cnt++;
                m[s[i]]+=1;
            }
            maxCnt=max(cnt,maxCnt);
        }
        return maxCnt;
    }
};