class Solution {
    bool checkPalindrome(string &s){
        int n = s.size();
        for(int i = 0; i <= n/2; i++){
            if(s[i] != s[n-1-i]){
                return false;
            }
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        return checkPalindrome(s) == true ? 1 : 2;
    }
};