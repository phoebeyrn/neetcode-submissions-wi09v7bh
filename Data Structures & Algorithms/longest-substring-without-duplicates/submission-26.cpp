class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<int> seen;
        int one = 0, two = 0;
        int res = 0;

        while(two < s.size())
        {
            if(seen.count(s[two]) == 0)
            {
                seen.insert(s[two]);
                res = max(res, two - one + 1);
                two++;
            }
            else
            {
                seen.erase(s[one]);
                one++;
            }
        }

        return res;
    }
};
