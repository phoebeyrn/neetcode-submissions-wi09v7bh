class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l = 0;
        int r = numbers.size() - 1;

        while(l < r)
        {
            if(numbers[r] + numbers[l] == target)
            {
                return {l + 1, r + 1};
            }
            if(numbers[r] + numbers[l] <= target)
            {
                l++; 
                continue;
            }
            if(numbers[r] + numbers[l] >= target)
            {
                r--;
                continue;
            }
        }

        return {l + 1, r + 1};
    }
};
