class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size + 1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        for(int index = 1; index <= size; index++){
            int countZero = count(strs[index-1].begin(),strs[index-1].end(),'0');
            int countOne = strs[index-1].size() - countZero;
            
            for(int zero = 0; zero <= m; zero++){
                for(int one = 0; one <= n; one++){
                    int notTake = dp[index-1][zero][one];
                    int take = 0;
                    if(countZero <= zero && countOne <= one){
                        take = 1 + dp[index-1][zero-countZero][one-countOne];
                    }
                    
                    dp[index][zero][one] = max(take,notTake);
                }
            }
        }
        return dp[size][m][n];
    }
};