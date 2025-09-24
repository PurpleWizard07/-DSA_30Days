class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int prev2 = 1; // dp[0] = 1 (empty string)
        int prev1 = 1; // dp[1] = 1 (first char is valid)

        for (int i = 2; i <= n; i++) {
            int curr = 0;

            // single digit (s[i-1])
            if (s[i - 1] != '0') {
                curr += prev1;
            }

            // two digits (s[i-2..i-1])
            int two = stoi(s.substr(i - 2, 2));
            if (two >= 10 && two <= 26) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
