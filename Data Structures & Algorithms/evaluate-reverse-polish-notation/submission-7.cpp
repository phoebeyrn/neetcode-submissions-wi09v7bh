class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long int> res;
        int a;
        int b;

        for(int i = 0; i < tokens.size(); i++)
        {
           if(tokens[i] == "+")
           {
                a = res.top(); res.pop();
                b = res.top(); res.pop();
                res.push(b + a);
           }
           else if(tokens[i] == "-")
           {
                a = res.top(); res.pop();
                b = res.top(); res.pop();
                res.push(b - a);
           }
           else if(tokens[i] == "*")
           {
                a = res.top(); res.pop();
                b = res.top(); res.pop();
                res.push(b * a);
           }
           else if(tokens[i] == "/")
           {
                a = res.top(); res.pop();
                b = res.top(); res.pop();
                res.push(b / a);
           }
           else
           {
                res.push(stoi(tokens[i]));
           }
        }

        return res.top();
    }

};
