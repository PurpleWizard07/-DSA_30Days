class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if(index == word.size()) {
            return true;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index]) {
            return false;
        }
        
        char temp = board[row][col];
        board[row][col] = '#'; // mark visited
        
        bool found = backtrack(board, word, index + 1, row + 1, col) ||
                     backtrack(board, word, index + 1, row - 1, col) ||
                     backtrack(board, word, index + 1, row, col + 1) ||
                     backtrack(board, word, index + 1, row, col - 1);
        
        board[row][col] = temp; // unmark visited
        
        return found;
    }
};
