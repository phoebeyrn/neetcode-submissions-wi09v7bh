class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
 std::unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            // If the number is already in the map, return true
            if (umap.find(nums[i]) != umap.end()) {
                return true;
            }

            // Otherwise, add the number to the map
            umap[nums[i]] = 1;  // You can store any value; it's used only for tracking
        }
        
        // No duplicates found
        return false;
    }
};
