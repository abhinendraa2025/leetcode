class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false; // first jump must be exactly 1 unit

        // map from stone position -> set of jump sizes that can land here
        unordered_map<int, unordered_set<int>> jumps;
        for (int stone : stones) jumps[stone] = {};
        jumps[stones[0]].insert(0);

        for (int i = 0; i < n; i++) {
            int stone = stones[i];
            for (int k : jumps[stone]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step <= 0) continue; // jump size must be positive
                    int next = stone + step;
                    if (next == stones[n - 1]) return true; // reached last stone
                    if (jumps.count(next)) {
                        jumps[next].insert(step);
                    }
                }
            }
        }

        return false;
    }
};