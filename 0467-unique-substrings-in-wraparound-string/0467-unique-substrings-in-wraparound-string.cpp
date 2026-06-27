class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';

            if (i > 0 && (s[i] - s[i-1] + 26) % 26 == 1)
                max_len++;
            else
                max_len = 1;

            dp[curr] = max(dp[curr], max_len);
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};