class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int i = 0;

        deque<int> dq;
        vector<int> maxes;

        while(i < nums.size())
        {
            while(!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if(!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            if(i >= k - 1) maxes.push_back(nums[dq.front()]);
            i++;
        }

        return maxes;
    }
};
