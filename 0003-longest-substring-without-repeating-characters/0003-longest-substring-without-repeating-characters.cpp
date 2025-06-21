
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, right = 0, maxLen = 0;

        while (right < s.length()) {
            if (charSet.count(s[right]) == 0) {
                // No duplicate — expand window
                charSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                // Duplicate — shrink window from the left
                charSet.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};