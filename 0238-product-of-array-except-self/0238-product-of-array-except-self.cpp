class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i=1; i<nums.size(); i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int r = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            ans[i] *= r;
            r *= nums[i];
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> pre(nums.size());
//         pre[0] = 1;
//         for(int i=1; i<nums.size(); i++) {
//             pre[i] = pre[i-1] * nums[i-1];
//         }
//         vector<int> post(nums.size());
//         post[nums.size()-1] = 1;
//         for(int i=nums.size()-2; i>=0; i--) {
//             post[i] = post[i+1] * nums[i+1];
//         }
//         vector<int> answer(nums.size());
//         for(int i=0; i<nums.size(); i++) {
//             answer[i] = pre[i]*post[i];
//         }
//         return answer;
//     }
// };