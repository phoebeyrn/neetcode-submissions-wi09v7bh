class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        if(position.size() != speed.size()) return -1;
        vector<pair<int, int>> cars;

        for(int i = 0; i < position.size(); i++)
        {
            cars.push_back(make_pair(position[i], speed[i]));
        }

        sort(cars.begin(), cars.end(), [] (const auto& a, const auto& b) 
        { 
            return a.first > b.first;
        });

        stack<pair<int, int>> fleets;

        for(int i = 0; i < cars.size(); i++)
        {
            if(fleets.empty())
            {
                fleets.push(cars[i]);
                continue;
            }

            double currCarVal = (double)(target - cars[i].first) / cars[i].second;
            double topVal = (double)(target - fleets.top().first) /  fleets.top().second;

            if(!fleets.empty() && topVal >= currCarVal)
            {
                continue;
            }
            
            fleets.push(cars[i]);
            
        }

        return fleets.size();
    }
};
