class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0,startColumn = 0;
        int endRow = matrix.size() - 1,endColumn = matrix[0].size() - 1;
        
        vector<int>res;
        if(matrix.size() == 0){
            return res;
        }
        while (startRow <= endRow && startColumn <= endColumn) {
            // Move towards right
            for (int j = startColumn; j <= endColumn; j ++) {
                res.push_back(matrix[startRow][j]);
            }
            startRow++;

            // Move towards down
            for (int i = startRow; i <= endRow; i ++) {
                res.push_back(matrix[i][endColumn]);
            }
            endColumn--;

            if (startRow <= endRow) {
                // Move towards left
                for (int j = endColumn; j >= startColumn; j --) {
                    res.push_back(matrix[endRow][j]);
                }
            }
            endRow--;

            if (startColumn <= endColumn) {
                // Move towards top
                for (int i = endRow; i >= startRow; i --) {
                    res.push_back(matrix[i][startColumn]);
                }
            }
            startColumn ++;
        }
        return res;
    }
};