class Solution {
public:
    int maxProfit(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> nextDay(2,vector<int>(3,0));
        
        for(int day = n-1; day >= 0; day--){
            vector<vector<int>> currentDay(2,vector<int>(3));
            for(int buy = 0; buy <= 1; buy++){
                for(int cnt = 0; cnt < 2; cnt++){
                    if(buy){
                        int b = -prices[day] + nextDay[0][cnt];
                        int nb = nextDay[1][cnt];
                        currentDay[buy][cnt] = max(b,nb);
                    }
                    else{
                        int s = prices[day] + nextDay[1][cnt+1];
                        int ns = 0 + nextDay[0][cnt];
                        currentDay[buy][cnt] = max(s,ns);
                    }
                }
            }
            nextDay = currentDay;
        }
        return nextDay[1][0];
    }

        
};

    
 /*
  Tabulation:
//      TC: O(nx2x3) 
//      SC: O(nx2x3)
     int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,
                         vector<vector<int>> (2,
                                vector<int>(3,0)));  
        
    // base cases:
        // any day if cnt >= 2 we can't buy sell anymore so d[][][cnt=2] = 0
        // if day >= n we can't buy sell anymore
//     
        for(int day = n-1; day >= 0; day--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cnt = 0; cnt < 2; cnt++){
                    // note if cnt >= 2 we can't buy sell anymore
                    if(buy){
                        int b = -prices[day] + dp[day+1][0][cnt];
                        int nb = dp[day+1][1][cnt];
                        dp[day][buy][cnt] = max(b,nb);
                    }
                    else{
                        int s = prices[day] + dp[day+1][1][cnt+1];
                        int ns = dp[day+1][0][cnt];
                        dp[day][buy][cnt] = max(s,ns);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
Memoization:
    TC: O(N x 2 x 3) 
    SC: O(N)
    int f(int day,int buy,int cnt,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(day == prices.size() || cnt >= 2){
            return 0;
        }
        else if(dp[day][buy][cnt] != -1){
            return dp[day][buy][cnt];
        }
        
        if(buy){
            int b = -prices[day] + f(day+1,!buy,cnt,prices,dp);
            int nb = f(day+1,buy,cnt,prices,dp);
            return dp[day][buy][cnt] = max(b,nb);
        }
        else{
            int s = prices[day] + f(day+1,!buy,cnt+1,prices,dp);
            int ns = f(day+1,buy,cnt,prices,dp);
            return dp[day][buy][cnt] = max(s,ns);
        }
    }
    
    
Recursion:
    TC: Exponential 
    SC: O(N)
    int f(int day,int buy,int cnt,vector<int> &prices){
        if(day == prices.size() || cnt >= 2){
            return 0;
        }
        
        
        if(buy){
            int b = -prices[day] + f(day+1,!buy,cnt,prices);
            int nb = f(day+1,buy,cnt,prices,dp);
            return max(b,nb);
        }
        else{
            int s = prices[day] + f(day+1,!buy,cnt+1,prices);
            int ns = f(day+1,buy,cnt,prices);
            return max(s,ns);
        }
    }
    
    
    
   { //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n,
    //                                   vector<vector<int>> (2,
    //                                                       vector<int>(3,-1)));
    //     return f(0,1,0,prices,dp);
      }  
        
    */