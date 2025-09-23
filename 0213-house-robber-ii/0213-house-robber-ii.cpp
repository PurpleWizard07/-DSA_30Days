class Solution {
public:
    int robLinear(vector<int>& nums, int l, int r) {
        int prev2 = 0, prev1 = 0;
        for (int i = l; i <= r; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: exclude last house
        int case1 = robLinear(nums, 0, n-2);

        // Case 2: exclude first house
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2);
    }
};
