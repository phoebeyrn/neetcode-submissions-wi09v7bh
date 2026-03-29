class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int l = 0, r = 0;

        deque<int> dq;
        vector<int> maxes;

        while(r < nums.size())
        {
            while(!dq.empty() && nums[r] > nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(r);

            if(!dq.empty() && dq.front() <= r - k)
            {
                dq.pop_front();
            }

            if(r >= k - 1) maxes.push_back(nums[dq.front()]);
            r++;
        }

        return maxes;
    }
};
