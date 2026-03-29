class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if(strs.empty()) return {};

        vector<vector<string>> res;
        unordered_map<string, vector<string>> freq;

        for(int i = 0; i < strs.size(); i++)
        {
            string a = strs[i];
            sort(a.begin(), a.end());

            freq[a].push_back(strs[i]);
        }
        
        for(auto const& f : freq)
        {
            res.push_back(f.second);
        }

        return res;
    }
    
};
