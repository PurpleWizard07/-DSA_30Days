class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=n-1; i>=2; i--) {
            long long c = nums[i];
            long long b = nums[i-1];
            long long a = nums[i-2];
            if(a+b > c) return a+b+c;
        }
        return 0;
    }
};