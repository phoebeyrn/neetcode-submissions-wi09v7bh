class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxPrice = 0;

        while(right < prices.size())
        {
            if(prices[left] > prices[right])
            {
                left = right;
            }
            if(prices[right] - prices[left] > maxPrice)
            {
                maxPrice = prices[right] - prices[left];
            }
            right++;
        }

        return maxPrice;
    }
};
