class Solution {
public:
    
    void setZeroes(vector<vector<int>> &matrix){
        int N = matrix.size();
        int M = matrix[0].size();
        
        int firstRow = 1,firstCol = 1;
        
        // check for zero in first col
        for(int i = 0; i < N; i++){
            if(matrix[i][0] == 0){
                firstCol = 0;
            }
        }
        // check for zero in first row
        for(int j = 0; j < M; j++){
            if(matrix[0][j] == 0){
                firstRow = 0;
            }
        }
        
        // mark first row and first col of matrix as markers
        for(int i = 1; i < N; i++){
            for(int j = 1; j < M; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        // corresponding to markers set zero in whole matrix
        for(int i = 1; i < N; i++){
            for(int j = 1; j < M; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // set first row on the basis of firstRow
        if(firstRow == 0){
            for(int j = 0; j < M; j++){
                matrix[0][j] = 0;
            }
        }
        
        // set first col on the basis of firstCol
        if(firstCol == 0){
            for(int i = 0; i < N; i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
//     TC: O(MN + MN) SC:O(M+N)
//     void setZeroes(vector<vector<int>> &matrix){
//         int N = matrix.size();
//         int M = matrix[0].size();
        
//         vector<int> row(N,-1);
//         vector<int> col(M,-1);
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < M; j++){
//                 if(matrix[i][j] == 0){
//                     row[i] = col[j] = 0;
//                 }
//             }
//         }
        
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < M; j++){
//                 if(row[i] == 0 || col[j] == 0){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
    
    
// brute force :
//     TC:O(MN + MN + (M+N))
    
//     void setZero(int row,int col,vector<vector<int>> &matrix){
//         int N = matrix.size();
//         int M = matrix[0].size();
        
        
//         for(int i = 0; i < N; i++){
//             if(matrix[i][col] != 0){
//                 matrix[i][col] = -1;
//             }
//         }
//         for(int j = 0; j < M; j++){
//             if(matrix[row][j] != 0){
//                 matrix[row][j] = -1;
//             }
//         }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         int N = matrix.size();
//         int M = matrix[0].size();
        
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < M; j++){
//                 if(matrix[i][j] == 0){
//                     setZero(i,j,matrix);
//                 }
//             }
//         }
        
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < M; j++){
//                 if(matrix[i][j] == -1){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         return;
//     }
};