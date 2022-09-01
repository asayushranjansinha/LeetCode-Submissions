class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        
        int low = 0, high = (N*M) - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int row = mid/M;
            int col = mid%M;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};