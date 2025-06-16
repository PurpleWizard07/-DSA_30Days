class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    // Target in the left half
                    right = mid - 1;
                } else {
                    // Target in the right half
                    left = mid + 1;
                }
            }
            // Otherwise, right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    // Target in the right half
                    left = mid + 1;
                } else {
                    // Target in the left half
                    right = mid - 1;
                }
            }
        }

        return -1; // Not found
    }
};
