class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sum;

        for(int one = 0; one < nums.size(); one++)
        {
            int two = one + 1;
            int three = nums.size() - 1;

            if(one > 0 && nums[one] == nums[one-1]) 
            {
                continue;
            }

            while(two < three)
            {
                if(nums[one] + nums[two] + nums[three] == 0)
                {
                    sum.push_back({nums[one], nums[two], nums[three]});
                    three--;
                    two++;
                    while (two < three && nums[two] == nums[two - 1]) two++;
                    while (two < three && nums[three] == nums[three + 1]) three--;
                }
                else if(nums[one] + nums[two] + nums[three] > 0)
                {
                    three--;
                    continue;
                }
                else if(nums[one] + nums[two] + nums[three] < 0)
                {
                    two++;
                    continue;
                }
            }
        }

        return sum;
    }
};
