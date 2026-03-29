class MinStack 
{
private:
    stack<int> minStack;
    stack<int> currStack;

public:
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        currStack.push(val);

        if(minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }

    }
    
    void pop() 
    {
        if(minStack.top() == currStack.top()) minStack.pop();
        currStack.pop();
    }
    
    int top() 
    {
        return currStack.top();
    }
    
    int getMin() 
    {
        return minStack.top();
    }
};
