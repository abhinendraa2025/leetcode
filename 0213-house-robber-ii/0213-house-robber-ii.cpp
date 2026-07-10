class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        return max(robLinear(nums, 0, n - 2), 
                    robLinear(nums, 1, n - 1));
    }
    
private:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev = 0, curr = 0;
        for (int i = start; i <= end; i++) {
            int temp = max(curr, prev + nums[i]);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};