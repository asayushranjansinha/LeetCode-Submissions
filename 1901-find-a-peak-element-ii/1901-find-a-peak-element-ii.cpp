class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int lo = 0, hi = m - 1;
        
        // binary search will take log m operations 
        // since we are operating on m columns
        while(lo <= hi){
            // searching for mid column
            int midCol = (lo + (hi - lo)/2);
            int maxVal = 0;
            int maxRow = 0; // row of the maximum element in mid column
            
            // searching for maximum value in that column among all rows
            // will take n operations each time
            for(int row = 0; row < n; row++){
                int val = mat[row][midCol];
                if(val > maxVal){
                    maxRow = row; 
                    maxVal = val;
                }
            }
            

            int leftNbr = midCol == 0 ? -1 : mat[maxRow][midCol-1];
            int rightNbr = midCol == m-1 ? -1 : mat[maxRow][midCol+1];
            
            // since we already have the maximum in each col the below is not needed
            // int upNbr = maxRow == 0 ? -1 : mat[maxRow-1][midCol];
            // int downNbr = maxRow == n ? -1 : mat[maxRow+1][midCol];
            
            if(maxVal > leftNbr && maxVal > rightNbr){
                return {maxRow,midCol};
            }
            else if(leftNbr > maxVal){
                // possibility of finding greater element is more on left side
                hi = midCol - 1;
            }
            else{
                // possibility of finding greater element is more on right side
                lo = midCol + 1;
            }
        }
        return {-1,-1};
    }
};