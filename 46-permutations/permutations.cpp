class Solution 
{
private:
    void findPermutations(int pos,vector<int> perm,vector<vector<int>> &ans, map<int,bool> &visited)
    {
        if(pos==visited.size()){
            ans.push_back(perm);
            return;
        }
        for(auto it : visited)
        {
            if(!it.second){
                visited[it.first]=true;
                perm.push_back(it.first);
                findPermutations(pos+1,perm,ans,visited);
                //backtrack
                visited[it.first]=false;
                perm.pop_back(); 
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> ans;
        map<int,bool> visited;
        for(int i : nums)
        {
            visited[i]=false;
        }
        findPermutations(0,vector<int>(),ans,visited);
        return ans;
    }
};