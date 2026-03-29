class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0, r = 0;
        int maxS = 0;
        int size = 0;
        unordered_set<char> seen;

        while(r < s.size())
        {
            if(seen.count(s[r]) > 0)
            {
                seen.erase(s[l]);
                l++;
                size--;
                continue;
            }

            seen.insert(s[r]);
            size++;
            r++;
            maxS = max(maxS, size);
        }

        return maxS;
    }
};
