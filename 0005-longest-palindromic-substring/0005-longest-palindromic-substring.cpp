class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int maxLen = 1;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            // Odd length
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }

            // Even length
            left = i - 1;
            right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
