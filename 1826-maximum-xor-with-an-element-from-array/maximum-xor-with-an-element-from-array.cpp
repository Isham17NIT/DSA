class TrieNode{
    public:
        bool flag;
        vector<TrieNode*> children;
        TrieNode(bool flag_){
            flag=flag_;
            children=vector<TrieNode*>(2,nullptr);
        }
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode(false);
        }
        void insert(int num){
            TrieNode* temp=root;
            for(int i=31;i>=0;i--)
            {
                int x=num>>i;
                int digit=(x&1) ? 1 : 0;
                if(!temp->children[digit]){
                    temp->children[digit]=new TrieNode(false);
                }
                temp=temp->children[digit];
            }
            temp->flag=true;
            return;
        }
        int maxXor(int num, int m)
        {
            TrieNode* temp=root;
            if(!temp->children[0] && !temp->children[1]) //no number in trie which is <=m
                return -1;
            int ans=0;
            for(int i=31;i>=0;i--)
            {
                int x=num>>i;
                int digit=(x&1) ? 1 : 0; //digit at the ith pos of num
                if(temp->children[!digit]){
                    ans |= (1<<i);
                    temp=temp->children[!digit];
                }
                else{
                    temp=temp->children[digit];
                }
            }
            return ans;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        Trie t;
        int idx=0;
        vector<int> ans(queries.size(),-1);
        sort(nums.begin(),nums.end());
        vector<vector<int>> offlineQueries;
        for(int i=0;i<queries.size();i++)
        {
            offlineQueries.push_back({queries[i][1],queries[i][0],i}); // m, num, i
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        for(vector<int> q : offlineQueries)
        {
            while(idx<nums.size() && nums[idx]<=q[0]){
                t.insert(nums[idx]);
                idx++;
            }
            ans[q[2]] = t.maxXor(q[1], q[0]); // num, m
        }
        return ans;
    }
};