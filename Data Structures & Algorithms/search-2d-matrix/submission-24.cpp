class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int l = 0, r = ROWS * COLS - 1;

        while (l <= r) 
        {
            int m = (l + r) / 2;
            int val = matrix[m / COLS][m % COLS];  // convert flat index to 2D

            if (val == target) return true;
            else if (val < target) l = m + 1;
            else r = m - 1;
        }
        
        return false;
    }
};
