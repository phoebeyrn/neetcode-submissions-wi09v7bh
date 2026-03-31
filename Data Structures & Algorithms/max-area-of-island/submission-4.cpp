class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if(grid.size() < 1) return 0;

        int maxArea = 0;
        int row = grid.size(), column = grid[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == 1)
                {
                    int currArea = dfs(grid, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int row, int column)
    {
        int r = row;
        int c = column;

        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
        {
            return 0;
        }

        if(grid[r][c] == 0) return 0;

        grid[r][c] = 0;

        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }
};

/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size() < 1) return 0;

        int islands = 0;
        int row = grid.size(), column = grid[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
        {
            return;
        }

        if(grid[r][c] == '0') return;

        grid[r][c] = '0';

        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};

*/