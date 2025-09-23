class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int one = 0, two = 0; // dp[0] = 0, dp[1] = 0

        for (int i = 2; i <= n; i++) {
            int curr = min(one + cost[i-2], two + cost[i-1]);
            one = two;
            two = curr;
        }

        return two;
    }
};
