class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l = 0, r = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int maxLen = 0;

        while(r < s.size())
        {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            
            if((r - l + 1) - maxFreq > k)
            {
                freq[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};