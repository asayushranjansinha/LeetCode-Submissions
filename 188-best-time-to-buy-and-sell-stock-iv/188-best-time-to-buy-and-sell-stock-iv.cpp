class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
        vector<vector<int>> next(2,vector<int>(k+1,0));        
        for(int ind = n-1; ind >= 0; ind--){
            vector<vector<int>> curr(2,vector<int>(k+1,0));
            for(int buy = 0; buy <= 1; buy++){
                for(int tr = 1; tr <= k; tr++){
                    if(buy){
                       curr[buy][tr] = max(-prices[ind]+
                                              next[0][tr],
                                              next[1][tr]);
                    }else{
                       curr[buy][tr] = max(prices[ind]+
                                              next[1][tr-1],
                                             next[0][tr]);
                    }
                }
            }
            next = curr;
        }
        return next[1][k]; 
    }
};