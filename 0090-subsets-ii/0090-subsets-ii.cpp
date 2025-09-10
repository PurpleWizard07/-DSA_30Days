class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end()); // sort to group duplicates
        backtrack(nums, 0, subset, res);
        return res;
    }

    void backtrack(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset); // Every subset is valid
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue; // skip duplicates at same recursion level
            }
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, res);
            subset.pop_back(); // backtrack
        }
    }
};
