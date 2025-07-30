class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search on no of rows.
        int m = matrix.size();
        int n = matrix[0].size();
        int startRow = 0, endRow = m-1;
        while(startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]) {
                //found the row => Binary search on this row
                int left = 0, right = n-1;
                while(left <= right) {
                    int mid = left + (right-left)/2;
                    if (matrix[midRow][mid] == target) return true;
                    else if(matrix[midRow][mid] > target) right = mid-1;
                    else left = mid+1;
                }
                return false;
            } else if (target > matrix[midRow][n-1]) {
                startRow = midRow + 1;
            }
            else endRow = midRow - 1;
        }
        return false;
    }
};
