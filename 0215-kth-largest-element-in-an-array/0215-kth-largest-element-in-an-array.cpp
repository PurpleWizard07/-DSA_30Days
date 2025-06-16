class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int pivotIndex = left + rand() % (right - left + 1);
            int pivot = nums[pivotIndex];
            swap(nums[pivotIndex], nums[right]);

            int i = left;
            for (int j = left; j < right; ++j) {
                if (nums[j] < pivot) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            swap(nums[i], nums[right]);

            if (i == target) return nums[i];
            else if (i < target) left = i + 1;
            else right = i - 1;
        }

        return -1;  // should never hit
    }
};