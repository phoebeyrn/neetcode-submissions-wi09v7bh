class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> res(temperatures.size(), 0);
        stack<int> temps;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!temps.empty() && temperatures[i] > temperatures[temps.top()])
            {
                res[temps.top()] = i - temps.top();
                temps.pop();
            }

            temps.push(i);
        }

        return res;

    }
};
