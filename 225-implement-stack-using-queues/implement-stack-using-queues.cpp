class MyStack 
{
public:
    queue<int> q;
    MyStack() 
    {
        q=queue<int>();
    }
    
    void push(int x) 
    {
        q.push(x);
        int size = q.size();
        // Rotate the queue except the last element
        for(int i = 0; i < size - 1; i++) 
        {
            q.push(q.front());
            q.pop();
        }
        return;
    }
    
    int pop() 
    {
        if(empty())
            return -1;
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() 
    {
        return q.front();
    }
    
    bool empty() 
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */