class Solution {

private:
    int diff = 0;
    priority_queue<int> maxWeights;

public:
    int lastStoneWeight(vector<int>& stones) 
    {
        for(int i = 0; i < stones.size(); i++)
        {
            maxWeights.push(stones[i]);
        }

        while(maxWeights.size() > 1)
        {
            int top = maxWeights.top();
            maxWeights.pop();
            diff = top - maxWeights.top();
            maxWeights.pop();

            if(top < maxWeights.top())
            {
                break;
            }
            else if(top > maxWeights.top())
            {
                maxWeights.push(diff);
            }
            else
            {
                continue;
            }
        }

        if(!maxWeights.empty())
        {
            return maxWeights.top();
        }

        return 0;
    }
};
