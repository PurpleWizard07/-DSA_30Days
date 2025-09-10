class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        backtrack(candidates, target, 0, comb, res);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int index, vector<int>& comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue; // skip duplicates
            }
            if (candidates[i] > target) {
                break; // no need to continue
            }
            comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, comb, res); // move to next index
            comb.pop_back(); // backtrack
        }
    }
};
