class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n; // base cases

        int one = 1; // ways to reach step 1
        int two = 2; // ways to reach step 2

        for (int i = 3; i <= n; i++) {
            int temp = one + two; // current step = sum of previous two
            one = two;           // shift forward
            two = temp;
        }

        return two; // final answer
    }
};
