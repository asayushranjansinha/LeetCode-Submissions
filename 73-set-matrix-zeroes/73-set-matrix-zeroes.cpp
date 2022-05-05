class Solution {
public:
    
    void setZeroes(vector<vector<int>> &matrix){
        int N = matrix.size();
        int M = matrix[0].size();
        
        vector<int> row(N,-1);
        vector<int> col(M,-1);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(matrix[i][j] == 0){
                    row[i] = col[j] = 0;
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(row[i] == 0 || col[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
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