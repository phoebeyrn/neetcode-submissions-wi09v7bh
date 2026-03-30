class TimeMap 
{

private:
unordered_map<string, vector<pair<int, string>>> keys;

public:

int minIndex = INT_MAX;

    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        keys[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        int l = 0, r = keys[key].size() - 1;
        string candidate = "";
        int minIndex = INT_MAX;
        if(keys[key].size() < 1) return "";
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            if(keys[key][m].first <= timestamp)
            {
                if(minIndex > m) candidate = keys[key][m].second;

                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return candidate;
    }
};
