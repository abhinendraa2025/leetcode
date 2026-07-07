class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > reach) return false;       // can't get to index i
            reach = max(reach, i + nums[i]);    // farthest index reachable so far
            if (reach >= nums.size() - 1) return true; // can already reach the end
        }
        return true;
    }
};