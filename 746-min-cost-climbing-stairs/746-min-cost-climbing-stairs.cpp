class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2) {
            return min(cost[0],cost[1]);
        }
        
        int prev = cost[1];
        int prev2 = cost[0];
        
        for(int i = 2; i <= n; i++){
            int charge = min(prev,prev2);
            if(i != n) charge += cost[i];
            
            prev2 = prev;
            prev = charge;
        }
        return prev;
    }
};