class Solution {
public:
    bool isValid(string s) {
        stack<char> parens; char temp;

        if(s.size() == 0) return true;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') 
            { 
                parens.push(s[i]); 
            }
            else 
            { 
                if(parens.empty()) return false;
                temp = parens.top(); 
                if(s[i] == ']' && temp != '[') { return false; }
                if(s[i] == ')' && temp != '(') { return false; }
                if(s[i] == '}' && temp != '{') { return false; }
                parens.pop();
            }
        }

        return parens.empty();
    }
};
