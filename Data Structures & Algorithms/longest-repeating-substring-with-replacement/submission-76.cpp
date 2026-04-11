class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int maxFreq = 0;
        int l = 0, r = 0;
        int res = 0;

        unordered_map<char, int> seenChars;

        while(r < s.size())
        {
            seenChars[s[r]]++;
            maxFreq = max(maxFreq, seenChars[s[r]]);

            if((r - l + 1) - maxFreq > k)
            {
                seenChars[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
