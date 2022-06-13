class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<int> prev(n);
        
        for(int i = 0; i < n; i++){
            prev[i] = triangle[n-1][i];
        }
        
        for(int i = n - 1; i >= 0; i--){
            vector<int> curr(n);
            for(int j = i; j >= 0; j--){
                if(i == n - 1){
                    curr[j] = triangle[i][j];
                }else{
                    curr[j] = triangle[i][j] + min(prev[j],prev[j+1]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};