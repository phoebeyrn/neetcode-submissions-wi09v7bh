class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int l = 0, r = 1;
        int maxF = 0;

        while (r < prices.size())
        {
            if(prices[l] > prices[r])
            {
                l = r;
                r++;
                continue;
            }

            maxF = max(maxF, prices[r] - prices[l]);
            r++;
        }

        return maxF;
    }
};
