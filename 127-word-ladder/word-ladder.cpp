class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        map<string,bool> visited;
        visited[beginWord]=false;
        for(string s : wordList){
            visited[s]=false;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited[beginWord]=true;
        while(!q.empty())
        {
            pair<string,int> p=q.front();
            q.pop();
            for(int k=0;k<26;k++)
            {
                for(int i=0;i<beginWord.size();i++)
                {
                    string temp=p.first;
                    temp[i]='a'+k;
                    if(visited.find(temp)!=visited.end() && !visited[temp])
                    {
                        q.push({temp, p.second+1});
                        visited[temp]=true;
                        if(temp==endWord){
                            return p.second+1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};