class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;

        unordered_map<int, int> seen1;
        unordered_map<int, int> seen2;

        for(int i = 0; i < s.size(); i++)
        {
            seen1[s[i]]++;
            seen2[t[i]]++;
        }

        return seen1 == seen2;
    }
};
