class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map; // prefix sum -> frequency
        map[0] = 1;
        int sum = 0, count = 0;

        for(int num : nums) {
            sum += num;
            count += map[sum - k];
            map[sum]++;
        }

        return count;
    }
};




// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             int sum = 0;
//             for(int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if(sum == k) count++;
//             }
//         }
//         return count;
//     }
// };
