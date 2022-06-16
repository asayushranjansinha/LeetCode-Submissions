class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        int start,end;
        
        for(int gap = 0; gap < n; gap++){
            for(int i = 0,j = i + gap; i < n && j < n; i++,j++){
                if(gap == 0){
                    dp[i][j] = true;
                }else if (gap == 1){
                    if(s[i] == s[j]) dp[i][j] = true;
                }else {
                    if(s[i] == s[j] && dp[i+1][j-1] == true) dp[i][j] = true;
                }
                
                if(dp[i][j]){
                    start = i;
                    end = j;
                }
            }
            
        }
        
        string ans = "";
        for(int i = start; i <= end; i++){
                ans += s[i];
        }
        return ans;
    }
};