class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_freq(128, 0);
        vector<int> window_freq(128, 0);

        for(char c: t) {
            t_freq[c]++;
        }

        int left = 0, matched_chars = 0;
        int min_len = INT_MAX, start_index = 0;

        for(int right = 0; right < s.length(); right++) {
            char r = s[right]; // current character at right pointer
            window_freq[r]++;  // increase frequency
            if(t_freq[r] > 0 && window_freq[r] <= t_freq[r]) {
                matched_chars++;
            }

            //shrink window from left if current window is valid.
            //a window is valid if matched_chars equals total length of 't'
            while(matched_chars == t.length()) {
                int curr_window_len = right - left + 1;
                if(curr_window_len < min_len) {
                    min_len = curr_window_len;
                    start_index = left;
                }

                char l = s[left];
                window_freq[l]--; // decrement frequency for character leaving window

                //if added element is not same as lost one, we lose 1 matched_char.
                if(t_freq[l] > 0 && window_freq[l] < t_freq[l]) {
                    matched_chars--;
                }
                left++;
            }
        }
        if(min_len == INT_MAX) {
            return "";
        } else {
            return s.substr(start_index, min_len);
        }
    }
};
