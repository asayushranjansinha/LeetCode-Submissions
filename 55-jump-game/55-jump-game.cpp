class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndexReached = 0;
        
        if(n == 1){
            return true;
        }
        for(int i = 0; i < n-1 && maxIndexReached >= i; i++){
            maxIndexReached = max(maxIndexReached,
                                 i + nums[i]);
            if(maxIndexReached >= n-1){
                return true;
            }
        }
        return false;
    }
};

// DP: TC = O(n*m) SC = O(n)
//  int n = nums.size();
//         vector<bool> dp(n,false);
//         dp[n-1] = true;
        
//         for(int i = n - 2; i >= 0; i--){
//             for(int j = 1; j <= nums[i] && i + j < n; j++){
//                 if(dp[i+j] == true){
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[0];