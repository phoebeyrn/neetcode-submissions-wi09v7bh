class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int r = nums.size(), l = 0, m = r/2;

        if(nums[0] == target) return 0;

        while(l <= r)
        {   
            m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] > target) { r = m - 1; continue; }
            if(nums[m] < target) { l = m + 1; continue; }
        }

        return -1;
    }
};
