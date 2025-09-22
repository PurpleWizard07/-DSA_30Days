class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // directions (up, down, left, right)
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // DFS function
        function<void(int, int, vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& visited) {
            visited[r][c] = true;
            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // stay within bounds
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                // move only if not visited and height >= current height
                if (!visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, visited);
                }
            }
        };

        // Pacific borders → top row + left col
        for (int c = 0; c < cols; c++) dfs(0, c, pacific);
        for (int r = 0; r < rows; r++) dfs(r, 0, pacific);

        // Atlantic borders → bottom row + right col
        for (int c = 0; c < cols; c++) dfs(rows - 1, c, atlantic);
        for (int r = 0; r < rows; r++) dfs(r, cols - 1, atlantic);

        // collect cells that can reach both oceans
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};
