class Solution {
public:
    bool searchInRow(int target, vector<vector<int>>&matrix, int row){
        for(int i = 0; i < matrix[row].size(); i++){
            if(target == matrix[row][i]) return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int N = matrix.size();
        int M = matrix[0].size();
        
        for(int row = 0; row < N; row++){
            if(target >= matrix[row][0] && target <= matrix[row][M-1]){
                found = found || searchInRow(target,matrix,row);
            }    
        }
        return found;
    }
};