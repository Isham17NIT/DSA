class Solution 
{
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        int n=words.size();
        vector<string> ans;
    
        string prev=words[0];
        ans.push_back(prev);
        sort(prev.begin(),prev.end());

        for(int i=1;i<n;i++)
        {
            string curr=words[i];
            sort(curr.begin(),curr.end());
            if(curr==prev)
                continue;
            else{
                ans.push_back(words[i]);
                prev=curr;
            }
        }
        return ans;
    }
};