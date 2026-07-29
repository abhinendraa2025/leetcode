class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        
        // dp[op][left] = best score achievable from this point on,
        // given 'op' operations have been performed so far and
        // 'left' numbers have been taken from the front of nums.
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = op; left >= 0; left--) {
                int right = n - 1 - (op - left);
                
                int takeLeft  = multipliers[op] * nums[left]  + dp[op + 1][left + 1];
                int takeRight = multipliers[op] * nums[right] + dp[op + 1][left];
                
                dp[op][left] = max(takeLeft, takeRight);
            }
        }
        
        return dp[0][0];
    }
};