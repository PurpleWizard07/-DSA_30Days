class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> answer;
        unordered_set<int> seen(nums.begin(), nums.end());
        for(int i=1; i<=nums.size(); i++) {
            if(!seen.count(i)) answer.emplace_back(i);
        }
        return answer;
    }

};