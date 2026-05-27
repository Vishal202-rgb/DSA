class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rookRow, rookCol;
        // 1. Find the rook's position
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    rookRow = i;
                    rookCol = j;
                }
            }
        }
        int count = 0;
        // 2. Define directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // 3. Search in all 4 directions
        for (int i = 0; i < 4; ++i) {
            int r = rookRow + dr[i];
            int c = rookCol + dc[i];

            while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                if (board[r][c] == 'B') break; // Blocked by bishop
                if (board[r][c] == 'p') {      // Found a pawn
                    count++;
                    break;
                }
                // Keep moving in this direction
                r += dr[i];
                c += dc[i];
            }
        }
        return count;
    }
};