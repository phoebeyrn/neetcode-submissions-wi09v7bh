class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l = 0, r = 0;
        int maxS = 0;
        int maxF = 0;
        unordered_map<char, int> freq;

        while(r < s.size())
        {
            freq[s[r]]++;
            maxF = max(freq[s[r]], maxF);

            if((r - l + 1) - maxF > k)
            {
                freq[s[l]]--;
                l++;
            }

            maxS = max(maxS, (r - l + 1));
            r++;

        }

        return maxS;
    }
};
