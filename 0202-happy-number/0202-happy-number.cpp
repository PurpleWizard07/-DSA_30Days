// class Solution {
// public:
//     bool isHappy(int n) {
        
//     }
// };




class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);  // Mark current number as seen

            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;  // Use the result for the next iteration
        }

        return n == 1;  // If we exited because n == 1 → happy number
    }
};






// class Solution {
// public:
//     bool isHappy(int n) {
//         vector<int> nums;  // To track seen numbers
        
//         while (n != 1) {
//             // Check if this number has been seen before
//             for (int num : nums) {
//                 if (num == n) return false;  // Cycle detected
//             }

//             nums.push_back(n);  // Store current number
            
//             // Calculate sum of squares of digits
//             int sum = 0;
//             int temp = n;
//             while (temp) {
//                 sum += (temp % 10) * (temp % 10);
//                 temp /= 10;
//             }
            
//             n = sum;  // Update n with the sum
//         }

//         return true;  // n == 1 → happy number
//     }
// };
