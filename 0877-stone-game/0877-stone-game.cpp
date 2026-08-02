class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single pile, current player takes it
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        
        // Fill by increasing length of subarray
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                // Take from left or right end, subtract opponent's best net score
                dp[i][j] = max(piles[i] - dp[i + 1][j], 
                                piles[j] - dp[i][j - 1]);
            }
        }
        
        // Alice wins if her net score difference is positive
        return dp[0][n - 1] > 0;
    }
};