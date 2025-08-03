class Solution 
{
private:
    void findAllCombos(int idx,int k,int n,vector<int> comb,vector<vector<int>> &ans)
    {
        if(comb.size()==k){
            ans.push_back(comb);
            return;
        }
        if(idx==n+1)
            return;
        if(n-idx+1 + comb.size() < k) //can never form a comb of k numbers
            return;
        //pick
        comb.push_back(idx);
        findAllCombos(idx+1,k,n,comb,ans);
        //not pick
        comb.pop_back();
        findAllCombos(idx+1,k,n,comb,ans);
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        findAllCombos(1,k,n,vector<int>(),ans);
        return ans;
    }
};