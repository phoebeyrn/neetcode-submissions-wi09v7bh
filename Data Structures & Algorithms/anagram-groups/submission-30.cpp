class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if(strs.empty()) return {};

        vector<vector<string>> res;
        unordered_map<string, vector<string>> groups;
        vector<int> freq(26, 0);

        for(int i = 0; i < strs.size(); i++)
        {
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
            fill(freq.begin(), freq.end(), 0);
        }
        
        for(auto const& group : groups)
        {
            res.push_back(group.second);
        }

        return res;
    }
    
};
