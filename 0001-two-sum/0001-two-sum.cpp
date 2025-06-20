class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};




// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i=0; i<nums.size()-1; i++) {
//             for(int j=i+1; j<nums.size(); j++) {
//                 if(nums[i]+nums[j] == target)
//                     return {i, j};
//             }
//         }
//         return {};
//     }
// };