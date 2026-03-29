class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int index1;
        int index2;
        int tempVar;

        for(int i = 0; i < nums.size(); i++)
        {
            tempVar = target - nums[i];
            if(seen.find(target - nums[i]) != seen.end())
            {
                index1 = min(i, seen[tempVar]);
                index2 = max(i, seen[tempVar]);
            }
            seen[nums[i]] = i;
        }

        return {index1, index2};
    }
};
