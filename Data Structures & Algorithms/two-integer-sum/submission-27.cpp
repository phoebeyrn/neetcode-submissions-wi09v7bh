class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if(nums.empty()) return {0, 0};

        unordered_map<int, int> mapping;

        for(int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if(mapping.count(temp) > 0)
            {
                return {mapping[temp], i};
            }
            mapping[nums[i]] = i;
        }

        return {0, 0};
    }
};
