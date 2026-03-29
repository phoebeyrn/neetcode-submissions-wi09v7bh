class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int l = 0, r = ROWS - 1;

        while(l <= r)
        {
            int m = (l + r) / 2;
            if(matrix[m][COLS - 1] < target)
            {
                l = m + 1;
            }
            else if(target < matrix[m][0])
            {
                r = m - 1;
            }
            else break;
        }

        if(!(l <= r)) 
        {
            return false;
        }

        int row = (l + r) / 2;
        l = 0, r = COLS - 1;

        while(l <= r)
        {
            int m = (l + r) / 2;

            if(matrix[row][m] > target)
            {
                r = m - 1;
                continue;
            }
            else if(matrix[row][m] < target)
            {
                l = m + 1;
                continue;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};
