class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int l = 0, r = 1, max = 0;

        if(prices.size() == 0) return 0;

        while(r < prices.size())
        {
            if(prices[r] < prices[l] || prices[r] == prices[l])
            {
                l = r;
                r++;
                continue;
            }
            if(prices[r] > prices[l])
            {
                max = max > prices[r] - prices[l] ? max : prices[r] - prices[l];
                r++;
            }
        }
        return max;
    }
};