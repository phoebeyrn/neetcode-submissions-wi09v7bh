class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        vector<vector<int>> topK(nums.size() + 1);

        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for (auto& [num, count] : freq)
        {
            topK[count].push_back(num);
        }

        vector<int> result;
        for (int i = topK.size() - 1; i >= 0; i--)
        {
            for (int num : topK[i])
            {
                result.push_back(num);
                if (result.size() == k) return result; 
            }
        }

        return result;
    }
};
