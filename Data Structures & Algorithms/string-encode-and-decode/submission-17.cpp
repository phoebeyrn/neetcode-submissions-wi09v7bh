class Solution {
public:

    string encode(vector<string>& strs) 
    {
        if(strs.empty()) return "";
        string res = "";

        for(int i = 0; i < strs.size(); i++)
        {
            res += to_string(strs[i].length()) + '#' + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) 
    {
       if(s.length() <= 0) return {};

       vector<string> result;
       int pos = 0;
       while(pos < s.length())
       {
            int hash_pos = s.find('#', pos);
            int length = stoi(s.substr(pos, hash_pos - pos));
            pos = hash_pos + 1;
            result.push_back(s.substr(pos, length));
            pos += length;
       }

       return result;

    }
};
