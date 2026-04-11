class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;

        while(l <= r)
        {
            int m = l + (r - l) / 2;

            if(nums[m] == target) return m;

            if(nums[m] >= nums[l])
            {
                if(target > nums[m] || target < nums[l])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            else
            {
                if(target < nums[m] || target > nums[r])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};

/*
0 1 2 3 4 5 6 7
1 2 3 4 5 6 7 0
2 3 4 5 6 7 0 1
3 4 5 6 7 0 1 2
4 5 6 7 0 1 2 3
5 6 7 0 1 2 3 4
6 7 0 1 2 3 4 5
7 0 1 2 3 4 5 6
*/