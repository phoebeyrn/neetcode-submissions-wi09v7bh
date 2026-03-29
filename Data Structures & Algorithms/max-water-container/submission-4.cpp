class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int difference = 0;
        int temp = 0;
        int l = 0;
        int r = heights.size() - 1;
        
        while(l < r)
        {
            difference = difference > min(heights[l], heights[r]) * (r - l) ? difference : min(heights[l], heights[r]) * (r - l);
            if(heights[l] < heights[r])
            {
                l++;
                continue;
            }
            if(heights[l] > heights[r])
            {
                r--;
                continue;
            }
            l++;
            r--;
        }


        return difference;
    }
};
