class Solution {
public:
    string minWindow(string s, string t) 
    {
        int have = 0;
        string res = "";
        int l = 0, r = 0;
        unordered_map<char, int> strT;
        unordered_map<char, int> curr;

        for(auto c : t) strT[c]++;
        int need = strT.size();

        while(r < s.size())
        {
            curr[s[r]]++;
            if(strT.count(s[r]) && curr[s[r]] == strT[s[r]]) 
                have++;

            while(have == need)
            {
                string temp = s.substr(l, r - l + 1);
                if(res.empty() || temp.size() < res.size()) 
                    res = temp;

                curr[s[l]]--;
                if(strT.count(s[l]) && curr[s[l]] < strT[s[l]]) 
                    have--;
                l++;
            }

            r++;
        }

        return res;
    }
};