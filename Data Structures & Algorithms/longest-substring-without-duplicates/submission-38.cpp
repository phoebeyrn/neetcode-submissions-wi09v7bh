class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> substring;

        int l = 0, r = 0;
        int size = 0;
        int maximumLength = 0;

        while(r < s.size())
        {
           if(substring.count(s[r]) == 0)
           {
                size++;
                maximumLength = max(size, maximumLength);
                substring.insert(s[r]);
                r++;
                continue;
           }
           else
           {
                size--;
                substring.erase(s[l]);
                l++;
                continue;
           }
        }

        return maximumLength;
    }
};
