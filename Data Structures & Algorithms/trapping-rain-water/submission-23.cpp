class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.size() == 0) return 0;

        int l = 0, r = height.size() - 1; 
        int maxLeft = height[l], maxRight = height[r];
        int res = 0;

        while(l < r)
        {
            if(maxLeft >= maxRight)
            {
                r--;
                maxRight = maxRight > height[r] ? maxRight : height[r];
                res += maxRight - height[r];
            }
            else if(maxLeft < maxRight)
            {
                l++;
                maxLeft = maxLeft > height[l] ? maxLeft : height[l];
                res += maxLeft - height[l];
            }
        }

        return res;
    }
};

//RIP:
        // stack<int> heights;
        // int volume = 0;
        // int temp = 0;
        // heights.push(height[0]);

        // for(int i = 0; i < height.size(); i++)
        // {
        //     if(i == 0 && heights.top() == 0) { heights.pop(); continue; }
        //     if(heights.empty())
        //     {
        //         heights.push(height[i]);
        //     }
        //     if(height[i] >= heights.top())
        //     {
        //         heights.pop();
        //         heights.push(height[i]);
        //         volume += temp;
        //     }
        //     if(height[i] < heights.top())
        //     {
        //         temp += heights.top() - height[i];
        //         continue;
        //     }
        // }

        // return volume;