class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        for (int r = 0; r <= rows - 3; r++) {
            for (int c = 0; c <= cols - 3; c++) {
                if (isMagic(grid, r, c)) count++;
            }
        }
        return count;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        int seen[10] = {};
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val]++) return false;
            }
        }

        for (int i = r; i < r + 3; i++) {
            if (grid[i][c] + grid[i][c+1] + grid[i][c+2] != 15) return false;
        }

        for (int j = c; j < c + 3; j++) {
            if (grid[r][j] + grid[r+1][j] + grid[r+2][j] != 15) return false;
        }

        if (grid[r][c]   + grid[r+1][c+1] + grid[r+2][c+2] != 15) return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]   != 15) return false;

        return true;
    }
};