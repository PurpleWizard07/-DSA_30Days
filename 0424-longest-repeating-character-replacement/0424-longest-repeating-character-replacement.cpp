class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) {
            return 0;
        }

        vector<int> counts(26, 0);
        int l = 0;
        int maxF = 0;
        int maxLen = 0;

        for (int r = 0; r < s.length(); ++r) {
            counts[s[r] - 'A']++;
            maxF = max(maxF, counts[s[r] - 'A']);

            int winLen = r - l + 1;

            if (winLen - maxF > k) {
                counts[s[l] - 'A']--;
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};