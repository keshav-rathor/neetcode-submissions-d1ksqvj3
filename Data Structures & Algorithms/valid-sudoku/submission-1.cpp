class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> row;
        unordered_map<int,unordered_set<int>> col;
        unordered_map<int,unordered_set<int>> sq;

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char cell=board[i][j];
                if(cell=='.') continue;
                if(row[i].count(cell ) || col[j].count(cell ) || sq[(i / 3) * 3 + j / 3].count(cell)) return false;
                row[i].insert(cell);
                col[j].insert(cell);
                sq[(i/ 3) * 3 + j / 3].insert(cell);
            }
        }
        return true;

    }
};
