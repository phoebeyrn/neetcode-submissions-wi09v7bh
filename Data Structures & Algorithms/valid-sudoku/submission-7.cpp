class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> seen;

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.') continue;

                string row = string(1, board[i][j]) + "row" + to_string(i);
                string column = string(1, board[i][j]) + "column" + to_string(j);
                string box = string(1, board[i][j]) + "box" + to_string(i/3) + to_string(j/3);

                if(seen.count(row) > 0) return false;
                if(seen.count(column) > 0) return false;
                if(seen.count(box) > 0) return false;

                seen.insert(row);
                seen.insert(column);
                seen.insert(box);
            }
        }

        return true;
    }
};
