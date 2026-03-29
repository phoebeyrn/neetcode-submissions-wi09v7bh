class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        vector<vector<int>> topFreq(nums.size() + 1);
        vector<int> topK;
        //insert into map
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        //insert into buckets
        for(auto i : freq)
        {
            topFreq[i.second].push_back(i.first);
        }

        //output top k
        for(int i = topFreq.size() - 1; i >= 0; i--)
        {
            for(int num : topFreq[i])
            {
                topK.push_back(num);
                if(topK.size() == k) return topK;
            }
        }

        return topK;
    }
};
