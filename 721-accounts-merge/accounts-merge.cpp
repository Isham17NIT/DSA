class Solution {
public:
    int findUltimateParent(vector<int> &parent,int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x] = findUltimateParent(parent,parent[x]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string,int> emails;
        unordered_map<int,vector<string>> merged;

        vector<int> parent(accounts.size());
        for(int i=0;i<accounts.size();i++)
        {
            parent[i]=i; //initialse DSU
        }

        vector<vector<string>> ans;        

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(emails.find(mail)==emails.end())
                    emails[mail] = i;
                else
                {
                    int p1 = findUltimateParent(parent,i);
                    int p2 = findUltimateParent(parent,emails[mail]);
                    if(p1!=p2)
                        parent[p1]=p2;
                }
            }
        }

        for (auto& it : emails) 
        {
            int ul = findUltimateParent(parent, it.second); 
            merged[ul].push_back(it.first);
        }
        for(auto& it : merged)
        {
            if(!it.second.empty())
            {
                vector<string> account;
                account.push_back(accounts[it.first][0]); //add name
                sort(it.second.begin(),it.second.end()); //sort emails
                account.insert(account.end(), it.second.begin(), it.second.end());
                ans.push_back(account);
            }
        }
        return ans;
    }
};