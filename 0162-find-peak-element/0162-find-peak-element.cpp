class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If middle element is greater than its right neighbor,
            // then the peak is on the left side (including mid)
            if (nums[mid] > nums[mid + 1]) {
                right = mid;  // peak is at mid or to the left of mid
            } else {
                // If middle element is smaller than right neighbor,
                // then the peak must be on the right side
                left = mid + 1;
            }
        }

        // left == right, and pointing to a peak element
        return left;
    }
};
