class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int gap = 0; gap < n; gap++){
            // i = starting character 
            // j = ending char
            // i + gap = j
            for(int i = 0,j = i + gap; j < n; i++,j++){
                if(gap == 0){
                    dp[i][j] = true;
                    // single character is always palindrome
                }else if(gap == 1){
                    if(s[i] == s[j])
                        dp[i][j] = true;
                    //double character is palindrome iff extremities are equal
                }else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                        // extremes are equal & middle is also palindrom then it is palindrome
                    }
                }
                // since we are travelling diagonally, the middle part lies in i+1,j-1 or in 
                // other words diagonally down left
                
                if(dp[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
/*
    Brute Force:
        Create all substrings & for each substring check if it is a palindrome or not.
        TC: O(n3) SC: O(1)
        
    Optimized Approach 1: Gap Strategy by Pepcoding
    Pattern: Matrix Chain Multiplication
    
    Note: Not done mcm by striver yet, Date:22/05/22
*/