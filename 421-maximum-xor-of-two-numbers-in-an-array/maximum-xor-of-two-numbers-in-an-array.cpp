class TrieNode
{
    public:
        vector<TrieNode*> children;
        bool flag;
        TrieNode(bool flag_)
        {
            flag=flag_;
            children=vector<TrieNode*>(2, nullptr);
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
        void insert(int num)
        {
            TrieNode* temp=root;
            for(int i=0;i<32;i++)
            {
                int x=num>>(31-i);
                int digit= (x&1)>0 ? 1 : 0;
                if(!temp->children[digit])
                    temp->children[digit]=new TrieNode(false);
                    
                temp=temp->children[digit];
            }
            temp->flag=true; //end of number
        }
        int findMaxXor(int num)
        {
            int ans=0;
            TrieNode* temp=root;
            for(int i=0;i<32;i++)
            {
                int bitPos=31-i;
                int x=num>>bitPos;
                int digit=(x&1)>0 ? 1 : 0;
                if(temp->children[!digit]) // opposite bit present
                {   
                    temp=temp->children[!digit];
                    ans=(ans|(1<<bitPos));
                }
                else
                    temp=temp->children[digit];
            }
            return ans;
        }
};
class Solution 
{
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie t;
        for(int i : nums)
        {
            t.insert(i);
        }
        int maxXor=0;
        for(int i : nums)
        {
            maxXor=max(maxXor,t.findMaxXor(i));
        }
        return maxXor;
    }
};