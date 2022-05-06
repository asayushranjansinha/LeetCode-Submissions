class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n,vector<int> (2,-1));
        // return memoized(0,1,prices,dp);
        // return tabulation(prices);
        return spaceOptimization(prices);
    }
private:
    int spaceOptimization(vector<int> &prices){
        int n = prices.size();
        vector<long> nextDay(2,0);
        
        for(int day = n-1; day >= 0; day--){
            vector<long> currDay(2,0);
            for(int buy = 0; buy <= 1; buy++){
                if(buy){
                    currDay[buy] = max(-prices[day] + nextDay[0],
                                  0 + nextDay[1]);
                }
                else{
                    currDay[buy] = max(prices[day] + nextDay[1],
                                      0 + nextDay[0]);
                }
            }
            nextDay = currDay;
        }
        return nextDay[1];
    }
    int tabulation(vector<int> &prices){
        int n = prices.size();
        vector<vector<long>> dp(n+1,vector<long>(2,-1));
        dp[n][0] = dp[n][1] = 0;
        for(int day = n-1; day >= 0; day--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy){
                    dp[day][buy] = max(-prices[day] + dp[day+1][0],
                                      0 + dp[day+1][1]);
                }
                else{
                    dp[day][buy] = max(prices[day] + dp[day+1][1],
                                      dp[day+1][0]);
                }
            }
        }
        return dp[0][1];
    }
    int memoized(int day,int buy,vector<int> &prices,vector<vector<int>> &dp){
        if(day == prices.size()){
            return 0;
        }else if(dp[day][buy] != -1){
            return dp[day][buy];
        }
        
        if(buy){
            int b = -prices[day] + memoized(day+1,0,prices,dp);
            int nb = -0 + memoized(day+1,1,prices,dp);
            return dp[day][buy] = max(b,nb);
        }else{
            int s = prices[day] + memoized(day+1,1,prices,dp);
            int ns = 0 + memoized(day+1,0,prices,dp);
            return dp[day][buy] = max(s,ns);
        }
    }
    int bruteForce(int day,int buy,vector<int> &prices){
        if(day == prices.size()){
            return 0;
        }
        
        if(buy){
            int b = -prices[day] + bruteForce(day+1,0,prices);
            int nb = -0 + bruteForce(day+1,1,prices);
            return max(b,nb);
        }else{
            int s = prices[day] + bruteForce(day+1,1,prices);
            int ns = 0 + bruteForce(day+1,0,prices);
            return max(s,ns);
        }
    }
    
};