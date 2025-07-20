class Solution {
private:
    bool isOperator(string s)
    {
        return s=="+" || s=="-" || s=="/" || s=="*";
    }
    int calculate(int a,int b, string op)
    {
        if(op=="+")
            return a+b;
        else if(op=="-")
            return a-b;
        else if(op=="/")
            return a/b;
        return a*b;
    }
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        for(string t : tokens)
        {
            if(isOperator(t))
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(calculate(a,b,t));
            }
            else
                s.push(stoi(t));
        }
        return s.top();
    }
};