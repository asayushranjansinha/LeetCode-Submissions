class Solution {
    vector<vector<vector<int>>> dp;
    int helper(vector<string> &strs,int maxZeros, int maxOnes, int index){
        if(index == strs.size()){
            return 0;
        }
        if(dp[index][maxZeros][maxOnes] != -1){
            return dp[index][maxZeros][maxOnes];
        }
        
        int take = 0,notTake = 0;
        notTake = helper(strs,maxZeros,maxOnes,index+1);
        
        int countZeros = count(strs[index].begin(),strs[index].end(),'0');
        int countOnes = strs[index].size() - countZeros;
        
        if(countZeros <= maxZeros && countOnes <= maxOnes){
            take = 1 + helper(strs,maxZeros-countZeros,maxOnes-countOnes,index+1);
        }
        return dp[index][maxZeros][maxOnes] = max(take,notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        dp.resize(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs,m,n,0);
    }
};