class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        //push into vector of task and count
        vector<int> count(26, 0);
        for(char task : tasks)
        {
            count[task - 'A']++;
        }

        //push into prioQ maxheap
        priority_queue<int> maxHeap;
        for(auto counter : count)
        {
            if(counter > 0)
            {
                maxHeap.push(counter);
            }
        }

        //initialize time and queue vars
        int time = 0;
        queue<pair<int, int>> q;

        //go thru prioQ and queue
        while(!maxHeap.empty() || !q.empty())
        {
            time++;

            if(maxHeap.empty())
            {
                time = q.front().second;
            }
            else
            {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0)
                {
                    q.push({cnt, time + n});
                }
            }

            if(!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }

        }

        //return time
        return time;
    }
};
