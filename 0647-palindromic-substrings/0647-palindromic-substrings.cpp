class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += countPalindromes(s, i, i);     // odd length
            count += countPalindromes(s, i, i + 1); // even length
        }
        return count;
    }

    int countPalindromes(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};
