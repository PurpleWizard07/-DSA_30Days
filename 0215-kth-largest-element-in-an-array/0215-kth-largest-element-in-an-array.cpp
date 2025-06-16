class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;  // kth largest = (n-k)th smallest
        return quickSelect(nums, 0, nums.size() - 1, target);
    }

private:
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];  // pick last element as pivot
        int i = left;

        // Partition: move smaller elements to left
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);  // put pivot in correct place

        if (i == k) return nums[i];         // found kth smallest
        else if (i < k) return quickSelect(nums, i + 1, right, k); // search right
        else return quickSelect(nums, left, i - 1, k);              // search left
    }
};