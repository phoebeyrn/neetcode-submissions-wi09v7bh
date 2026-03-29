class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> seen;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                //if its a dot just move on.
                if(board[i][j] == '.') continue;

                //check if this number happens to be in the same row
                string sameRow = to_string(board[i][j]) + "row" + to_string(i);
                if(seen.count(sameRow)) return false;

                //check if this number happens to be in the same column
                string sameColumn = to_string(board[i][j]) + "column" + to_string(j);
                if(seen.count(sameColumn)) return false;

                //check if this number is in the same box
                string sameBox = to_string(board[i][j]) + "box" + to_string(i/3) + '+' + to_string(j/3);
                if(seen.count(sameBox)) return false;

                //insert if all checks pass
                seen.insert(sameRow);
                seen.insert(sameColumn);
                seen.insert(sameBox);
            }
        }

        return true;
    }
};
