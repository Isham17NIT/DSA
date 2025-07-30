class Solution 
{
private:
    void getCombinations(int idx,vector<int> &candidates,int target,vector<int> comb,vector<vector<int>> &s)
    {
        if(target==0){
            s.push_back(comb);
            return;
        }
        if(idx==candidates.size() || candidates[idx] > target)
            return;
        //pick
        comb.push_back(candidates[idx]);
        getCombinations(idx,candidates,target-candidates[idx],comb,s);
        //not pick
        comb.pop_back();
        getCombinations(idx+1,candidates,target,comb,s);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        getCombinations(0,candidates,target,vector<int>(),ans);
        return ans;
    }
};