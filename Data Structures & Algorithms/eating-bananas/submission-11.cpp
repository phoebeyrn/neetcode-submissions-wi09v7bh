class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        std::vector<int>::iterator max_it = std::max_element(piles.begin(), piles.end());
        int speed = *max_it;

        int l = 1;
        int r = *max_it - 1;

        while(l <= r)
        {
            int m = l + (r - l) / 2;
            double hours = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                hours += static_cast<double>(ceil((double)piles[i] / m));
            }

            if(hours <= h)
            {
                speed = min(m, speed);
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }

        }

        return speed;
    }
};
