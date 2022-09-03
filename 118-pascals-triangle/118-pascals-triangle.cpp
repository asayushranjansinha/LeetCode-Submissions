class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int N = numRows;
        
        vector<vector<int>>ans;
        for(int i = 0; i < N; i++){
            vector<int>level;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    level.push_back(1);
                }
                else if(i > 0){
                    int sum = ans[i-1][j] + ans[i-1][j-1];
                    level.push_back(sum);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};