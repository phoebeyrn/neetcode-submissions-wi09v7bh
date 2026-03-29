class Solution {
public:
    vector<string> stringOps;
    string curr;

    string encode(vector<string>& strs) 
    {
        string res;
        for (auto &str : strs) {
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) 
    {
        vector<string> res;
        size_t i = 0;
        while (i < s.size()) 
        {
            size_t pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));
            i = pos + 1;
            res.push_back(s.substr(i, len));
            i += len;
        }

        return res;
    }
};
