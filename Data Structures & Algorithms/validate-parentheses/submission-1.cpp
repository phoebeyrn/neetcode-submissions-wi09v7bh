class Solution {
public:
    bool isValid(string s) {
        stack<char> openings;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            openings.push(c);
        } 
        else {
            if (openings.empty()) return false;

            char top = openings.top();
            openings.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return openings.empty();


    }
};
