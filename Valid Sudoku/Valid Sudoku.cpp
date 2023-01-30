class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row, col, cube;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !row.insert(board[i][j]).second) return false;
                if (board[j][i] != '.' && !col.insert(board[j][i]).second) return false;
                int rowIndex = 3 * (i / 3) + j / 3;
                int colIndex = 3 * (i % 3) + j % 3;
                if (board[rowIndex][colIndex] != '.' && !cube.insert(board[rowIndex][colIndex]).second) return false;
            }
        }
        return true;
    }
};
