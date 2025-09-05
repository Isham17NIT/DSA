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
                if(x&1) // bit at bitPos is 1
                {
                    if(temp->children[0])
                    {
                        temp=temp->children[0];
                        ans=(ans|(1<<bitPos));
                    }
                    else
                        temp=temp->children[1];
                }
                else
                {
                    if(temp->children[1])
                    {
                        temp=temp->children[1];
                        ans=(ans|(1<<bitPos));
                    }
                    else
                        temp=temp->children[0];
                }
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