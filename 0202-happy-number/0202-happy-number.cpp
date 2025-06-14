class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums;  // To track seen numbers
        
        while (n != 1) {
            // Check if this number has been seen before
            for (int num : nums) {
                if (num == n) return false;  // Cycle detected
            }

            nums.push_back(n);  // Store current number
            
            // Calculate sum of squares of digits
            int sum = 0;
            int temp = n;
            while (temp) {
                sum += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            
            n = sum;  // Update n with the sum
        }

        return true;  // n == 1 → happy number
    }
};
