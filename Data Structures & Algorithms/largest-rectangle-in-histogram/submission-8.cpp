class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int maxH = 0;
        int area = 0;
        stack<int> a;

        for(int i = 0; i < heights.size(); i++)
        {
            while(!a.empty() && heights[a.top()] > heights[i])
            {
                int top = a.top();
                int topH = heights[a.top()];
                int left;
                a.pop();
                if(a.empty()) left = i;
                else left = i - a.top() - 1;
                int width = a.empty() ? i : i - a.top() - 1;
                maxH = max(maxH, topH);
                area = max(area, width * topH);
            }

            if(a.empty() || heights[a.top()] <= heights[i])
            {
                a.push(i);
            }
        }

        while(!a.empty())
        {
            int top = a.top();
            int topH = heights[top];
            a.pop();
            int left = a.empty() ? 0 : a.top() + 1;
            int width = a.empty() ? heights.size() : heights.size() - a.top() - 1;
            area = max(area, width * topH);
        }

        return area;
    }
};
