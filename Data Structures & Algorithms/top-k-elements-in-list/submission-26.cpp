class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if(nums.size() < 1) return {};

        unordered_map<int, int> frequency;

        for(int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
        }

        vector<vector<int>> grouping(nums.size() + 1);

        for(auto const& s : frequency)
        {
            grouping[s.second].push_back(s.first);
        }

        vector<int> topK;

        for(int i = grouping.size() - 1; i >= 0; i--)
        {
            for (int num : grouping[i])
            {
                topK.push_back(num);
                if (topK.size() == k) return topK; 
            }
        }

        return topK;
    }
};
