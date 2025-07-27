class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        string chars = "ACGT";
        map<string,bool> visited;
        visited[startGene]=false;
        for(string s : bank)
        {
            visited[s]=false;;
        }
        int charDiff=0;
        for(int i=0;i<8;i++)
        {
            if(startGene[i]!=endGene[i])
                charDiff+=1;
        }
        queue<pair<string,int>> q;
        q.push({startGene,0});
        visited[startGene]=true;
        while(!q.empty())
        {
            pair<string,int> curr = q.front();
            q.pop();
            for(char c : chars)
            {
                for(int i=0;i<8;i++)
                {
                    if(curr.first[i]==c)
                        continue;
                    string temp = curr.first;
                    temp[i]=c; //one mutation at a time
                    if(visited.find(temp)!=visited.end() && !visited[temp])
                    {
                        visited[temp]=true;
                        q.push({temp,curr.second+1});
                        if(temp==endGene)
                            return curr.second+1;
                    }
                }
            }
        }
        return -1;
    }
};