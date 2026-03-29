class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<char, int> seen;
        unordered_map<char, int> seenCheck;

        for(int i = 0; i < s.length(); i++)
        {
            seen[s[i]]++;
            seenCheck[t[i]]++;
        }
        return seen == seenCheck;
    }
};
