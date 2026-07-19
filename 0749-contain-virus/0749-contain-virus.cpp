class Solution {
public:
    int rows, cols;
    
    int containVirus(vector<vector<int>>& isInfected) {
        rows = isInfected.size();
        cols = isInfected[0].size();
        int totalWalls = 0;
        
        while (true) {
            vector<vector<int>> visited(rows, vector<int>(cols, 0));
            vector<vector<pair<int,int>>> regions;          // infected cells per region
            vector<unordered_set<int>> threatenedCells;     // unique threatened cells per region
            vector<int> wallsNeeded;                        // walls needed per region
            
            int maxThreatened = -1, maxIdx = -1;
            
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        vector<pair<int,int>> region;
                        unordered_set<int> threatened;
                        int walls = 0;
                        
                        dfs(isInfected, visited, i, j, region, threatened, walls);
                        
                        regions.push_back(region);
                        threatenedCells.push_back(threatened);
                        wallsNeeded.push_back(walls);
                        
                        if ((int)threatened.size() > maxThreatened) {
                            maxThreatened = threatened.size();
                            maxIdx = regions.size() - 1;
                        }
                    }
                }
            }
            
            // No region threatens any new cell -> stop
            if (maxThreatened <= 0) break;
            
            // Wall off the most-threatening region permanently
            totalWalls += wallsNeeded[maxIdx];
            for (auto& cell : regions[maxIdx]) {
                isInfected[cell.first][cell.second] = 2;
            }
            
            // Spread all other regions by one layer
            for (int k = 0; k < (int)regions.size(); k++) {
                if (k == maxIdx) continue;
                for (int code : threatenedCells[k]) {
                    int r = code / cols, c = code % cols;
                    isInfected[r][c] = 1;
                }
            }
        }
        
        return totalWalls;
    }
    
private:
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j,
             vector<pair<int,int>>& region, unordered_set<int>& threatened, int& walls) {
        visited[i][j] = 1;
        region.push_back({i, j});
        
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || ni >= rows || nj < 0 || nj >= cols) continue;
            
            if (grid[ni][nj] == 1 && !visited[ni][nj]) {
                dfs(grid, visited, ni, nj, region, threatened, walls);
            } else if (grid[ni][nj] == 0) {
                threatened.insert(ni * cols + nj);
                walls++;  // one wall per infected-uninfected edge
            }
        }
    }
};