class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // considering a 2D matrix as a 1D matrix using imaginary indices starting from 0 to (rows*cols) - 1
        // actual column number is index % cols 
        // actual row number is index / cols
        
        int start = 0, end = (rows * cols) - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int row = mid / cols;
            int col = mid % cols;
            
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target){
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return false;
    }
};