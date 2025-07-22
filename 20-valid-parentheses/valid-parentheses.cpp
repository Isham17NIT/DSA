class Solution {
public:
    bool isValid(string str) 
    {
        unordered_map<char, char> pairs = {  {'(',')'},  {'{','}'},  {'[',']'}  };
        stack<char> s;
        for(char c : str)
        {
            if(pairs.find(c)!=pairs.end()) //open bracket
                s.push(c);
            else //close bracket
            {
                if(s.empty())
                    return false;
                char open = s.top();
                if(pairs[open]!=c)
                    return false;
                else
                    s.pop();
            }
        }
        return s.empty();
    }
};