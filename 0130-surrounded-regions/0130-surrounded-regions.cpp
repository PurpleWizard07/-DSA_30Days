class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int rows = board.size();
        int cols = board[0].size();

        // DFS lambda
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O')
                return;
            board[r][c] = '#'; // mark as safe
            dfs(r+1, c);
            dfs(r-1, c);
            dfs(r, c+1);
            dfs(r, c-1);
        };

        // Step 1: Mark border-connected 'O's
        for (int r = 0; r < rows; r++) {
            dfs(r, 0);          // left border
            dfs(r, cols-1);     // right border
        }
        for (int c = 0; c < cols; c++) {
            dfs(0, c);          // top border
            dfs(rows-1, c);     // bottom border
        }

        // Step 2: Flip cells
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X'; // surrounded
                if (board[r][c] == '#') board[r][c] = 'O'; // safe
            }
        }
    }
};
