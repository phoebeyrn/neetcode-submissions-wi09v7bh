class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;

        while(l != r)
        {
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] <= nums[r])
            {
                if(target >= nums[m] && target <= nums[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            else
            {
                if(target >= nums[l] && target <= nums[m])
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
        }

        return nums[l] == target ? l : -1;  
    }
};
