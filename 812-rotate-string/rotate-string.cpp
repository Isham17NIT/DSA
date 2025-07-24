class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.length()!=goal.length())
            return false;
        s = s + s;
        return s.contains(goal); // whether goal is a rotation of s
    }
};