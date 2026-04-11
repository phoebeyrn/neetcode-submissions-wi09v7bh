class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        vector<vector<int>> topK(nums.size() + 1);

        for(const auto& keys : freq)
        {
            topK[keys.second].push_back(keys.first); 
        }

        vector<int> res;
        for(int i = topK.size() - 1; i > 0; --i)
        {
            for(int i : topK[i])
            {
                res.push_back(i);
                if(res.size() == k)
                {
                    return res;
                }
            }
        }

        return res;
    }
};
