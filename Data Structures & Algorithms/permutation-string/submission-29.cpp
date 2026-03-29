class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int l = 0, r = 0;
        unordered_map<char, int> string1;
        unordered_map<char, int> perm;
        int size = 0;

        for(auto s : s1) string1[s]++;

        while(r < s2.size())
        {
            perm[s2[r]]++;

            if(r - l + 1 > s1.size())
            {
                perm[s2[l]]--;
                if(perm[s2[l]] == 0) perm.erase(s2[l]);
                l++;
            }

            if(string1 == perm)
            {
                return true;
            }


            r++;
        }

        return false;

    }
};
