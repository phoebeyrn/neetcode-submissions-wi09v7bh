class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if(strs.empty()) return {};

        vector<vector<string>> res;
        unordered_map<string, vector<string>> groups;

        for(int i = 0; i < strs.size(); i++)
        {
            vector<int> freq(26, 0);
            string temp = strs[i];
            for(int s : temp)
            {
                freq[s - 'a']++;
            }

            string key = "";
            for(auto f : freq) 
            {
                key += to_string(f) + ",";
            }

            groups[key].push_back(strs[i]);
        }
        
        for(auto const& group : groups)
        {
            res.push_back(group.second);
        }

        return res;
    }
    
};
