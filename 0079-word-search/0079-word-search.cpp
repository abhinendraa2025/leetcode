class Solution {
public:
    int rows, cols;
    
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[idx]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';  // mark as visited
        
        bool found = dfs(board, word, i+1, j, idx+1) ||
                     dfs(board, word, i-1, j, idx+1) ||
                     dfs(board, word, i, j+1, idx+1) ||
                     dfs(board, word, i, j-1, idx+1);
        
        board[i][j] = temp;  // backtrack
        
        return found;
    }
};