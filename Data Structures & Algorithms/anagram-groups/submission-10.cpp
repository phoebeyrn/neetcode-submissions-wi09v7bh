class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> storage;

        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            storage[temp].push_back(strs[i]);
        }

        for(auto str : storage)
        {
            res.push_back(str.second);
        }

        return res;
    }
    
};
