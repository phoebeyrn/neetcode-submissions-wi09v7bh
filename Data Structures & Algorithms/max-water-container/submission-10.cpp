class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        if(heights.size() < 1) return -1;

        int l = 0, r = heights.size() - 1;
        int maximum = 0;

        //formula: min(l, r) x l - r

        while(l < r)
        {
            maximum = max(maximum, (min(heights[l], heights[r]) * (r - l)));

            if(heights[l] <= heights[r])
            {
                l++;
                continue;
            }
            else 
            {
                r--;
                continue;
            }
        }

        return maximum;
    }
};
