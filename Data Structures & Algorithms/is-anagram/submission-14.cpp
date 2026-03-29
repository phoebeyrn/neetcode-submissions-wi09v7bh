class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> sstring;
        unordered_map<char, int> tstring;

        for(int i = 0; i < s.size(); i++)
        {
            sstring[s[i]]++;
            tstring[t[i]]++;
        }

        return sstring == tstring;
    }
};
