class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        // First pass: count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Second pass: find the number that appears once
        for (auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1;
    }
};