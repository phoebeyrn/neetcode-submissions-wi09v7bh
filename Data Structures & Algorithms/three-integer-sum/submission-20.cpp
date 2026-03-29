class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size() < 1) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;


        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size() - 1;
                while(j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum < 0)
                    {
                        j++;
                        continue;
                    }
                    else if (sum > 0)
                    {
                        k--;
                        continue;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[k]});
                        while(nums[j] == nums[j+1]) j++;
                        while(nums[k] == nums[k-1]) k--;
                        j++;
                        k--;
                    }
                }
        }

        return res;
    }
};
