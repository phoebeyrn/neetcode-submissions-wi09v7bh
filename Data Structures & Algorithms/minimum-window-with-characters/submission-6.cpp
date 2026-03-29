class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(t.empty() || s.empty()) return "";
        
        unordered_map<char, int> stringT, freq;
        
        for(char c : t) stringT[c]++;
        
        int have = 0, need = stringT.size();
        int l = 0;
        int minLen = INT_MAX;
        string res = "";

        for(int r = 0; r < s.size(); r++)
        {
            freq[s[r]]++;
            
            if(stringT.count(s[r]) && freq[s[r]] == stringT[s[r]])
            {
                have++;
            }

            while(have == need)
            {
                if(r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }
                
                freq[s[l]]--;
                if(stringT.count(s[l]) && freq[s[l]] < stringT[s[l]])
                {
                    have--;
                }
                l++;
            }
        }

        return res;
    }
};