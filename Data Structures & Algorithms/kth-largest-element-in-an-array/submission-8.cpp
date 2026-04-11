class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> topK;

        for(int i = 0; i < nums.size(); i++)
        {

                topK.push(nums[i]);


            if(topK.size() > k)
            {
                topK.pop();
            }
        }

        return topK.top();
    }
};
