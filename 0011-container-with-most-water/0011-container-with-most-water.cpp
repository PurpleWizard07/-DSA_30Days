class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxi = 0;
        while(left < right) {
            int area = min(height[left], height[right]) * (right-left);
            maxi = max(maxi, area);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxi;
    }
};