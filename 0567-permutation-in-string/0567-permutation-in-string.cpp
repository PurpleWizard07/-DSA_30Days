class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        vector<int> s1_freq(26, 0);
        vector<int> window_freq(26, 0);

        for(int i=0; i<len1; i++) {
            s1_freq[s1[i] - 'a']++;
            window_freq[s2[i] - 'a']++;
        }

        if(s1_freq == window_freq) return true;

        for(int right = len1; right < len2; right++) {
            window_freq[s2[right] - 'a']++;
            window_freq[s2[right-len1] - 'a']--;

            if(s1_freq == window_freq) return true;
        }
        return false;
    }
};
