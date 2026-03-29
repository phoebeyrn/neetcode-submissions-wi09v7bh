class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int l = 0, r = 0;
        unordered_map<char, int> string1;
        unordered_map<char, int> freq;

        for(int i = 0; i < s1.size(); i++)
        {
            string1[s1[i]]++;
        }

        while(r < s2.size())
        {
            freq[s2[r]]++;
            r++;

            if(r - l > s1.size())
            {
                freq[s2[l]]--;
                if(freq[s2[l]] == 0) freq.erase(s2[l]);
                l++;
            }

            if(string1 == freq)
            {
                return true;
            }

        }

        return false;
    }
};
