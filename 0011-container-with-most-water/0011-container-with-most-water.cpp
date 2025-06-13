class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxi = 0;
        
        while (left < right) {
            // Use long long to prevent overflow
            long long area = min(height[left], height[right]) * (right - left);
            maxi = max(maxi, (int)area);
            
            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) left++;
            else right--;
        }
        
        return maxi;
    }
};