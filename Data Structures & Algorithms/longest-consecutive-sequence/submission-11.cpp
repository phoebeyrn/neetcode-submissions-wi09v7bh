class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> seen;
        int min = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            seen.insert(nums[i]);
        }
        for(auto num : seen)
        {
            if (seen.find(num - 1) == seen.end())
            {
                int length = 1;
                while(seen.find(num+length) != seen.end())
                {
                    length++;
                }
                min = min > length ? min : length;
            }
        }

        return min;
    }
};
