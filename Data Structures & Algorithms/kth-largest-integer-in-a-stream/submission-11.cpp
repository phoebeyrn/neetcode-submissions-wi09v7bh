class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> stream;
    int kLargest;
public:
    KthLargest(int k, vector<int>& nums) {
        kLargest = k;
        for(int i = 0; i < nums.size(); i++)
        {
            add(nums[i]);
        }
    }
    
    int add(int val) 
    {
        stream.push(val);
        if(stream.size() > kLargest)
        {
            stream.pop();
        }
        return stream.top();
    }
};
