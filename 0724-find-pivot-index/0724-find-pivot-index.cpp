class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto num: nums) {
            sum += num;
        }
        int left_sum = 0;
        int right_sum = sum;
        for(int i=0; i<n; i++) {
            right_sum -= nums[i];
            if(left_sum == right_sum) return i;
            left_sum += nums[i];
        }
        return -1;
    }
};




// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> left(n);
//         vector<int> right(n);
//         left[0] = nums[0], right[n-1] = nums[n-1];
//         for(int i=1; i<n; i++) {
//             left[i] = left[i-1] + nums[i];
//         }
//         for(int i=n-2; i>=0; i--) {
//             right[i] = right[i+1] + nums[i];
//         }
//         for(int i=0; i<n; i++) {
//             if(left[i] == right[i]) return i;
//         }
//         return -1;
//     }
// };