class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> history;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++)
        {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            string add = strs[i];
            history[sorted].push_back(add); 
        }
        
        for(auto& str : history) 
        {
            res.push_back(str.second);
        }

        return res;
    }
    
};
