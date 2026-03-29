class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> seen;
        int tempVar = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            tempVar = target - nums[i];
            if(seen.find(tempVar) != seen.end())
            {
                return {seen[tempVar], i};
            }
            seen[nums[i]] = i;
        }

        return {0, 0};
    }
};
