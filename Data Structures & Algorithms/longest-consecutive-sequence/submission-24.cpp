class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
       int maxSeq = 0;
       unordered_set<int> seq;

        for(int i = 0; i < nums.size(); i++)
        {
            seq.insert(nums[i]);
        }

       for(int i = 0; i < nums.size(); i++)
       {
        int j = 1;
        int tempMax = 1;

        if(seq.count(nums[i] - 1) == 0)
        {
            while(seq.count(nums[i] + j) > 0)
            {
                tempMax++;
                j++;
            }
            
            maxSeq = max(tempMax, maxSeq);
        }
       }

       return maxSeq;
    }
};
