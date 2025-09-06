class TrieNode
{
    public:
        bool flag;
        vector<TrieNode*> children;
        TrieNode(bool flag_)
        {
            flag=flag_;
            children=vector<TrieNode*>(26,nullptr);
        }
};
class Trie
{
    private:
        TrieNode* root;
    public:
        Trie()
        {
            root=new TrieNode(false);
        }
        void insert(string s)
        {
            TrieNode* temp=root;
            for(char c : s)
            {
                if(!temp->children[c-'a'])
                {
                    temp->children[c-'a']=new TrieNode(false);
                }
                temp=temp->children[c-'a'];
            }
            temp->flag=true; //indicates end of word
        }
        bool areAllPrefixesPresent(string s)
        {
            TrieNode* temp=root;
            for(char c : s)
            {
                if(!temp->children[c-'a']->flag)
                    return false;
                temp=temp->children[c-'a'];
            }
            return true;
        }
};
class Solution 
{
    public:
        string longestValidWord(vector<string>& words) 
        {
            Trie t;
            string ans="";
            int maxLength=0;
            for(string s : words)
            {
                t.insert(s);
            }
            for(string s : words)
            {
                if(t.areAllPrefixesPresent(s))
                {
                    if(maxLength < s.length()){
                        ans=s;
                        maxLength=s.length();
                    }
                    else if(maxLength == s.length() && s<ans)
                        ans = s; 
                }
            }
            return ans;
        }
};












