class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False
            
        
        """
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) 
        {
            if (umap.find(nums[i]) != umap.end()) 
            {
                return true;
            }
            umap[nums[i]] = 1; 
        }
        
        return false;
        """