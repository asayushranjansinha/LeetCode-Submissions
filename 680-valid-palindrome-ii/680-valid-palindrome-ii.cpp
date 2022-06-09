class Solution {
    bool isPalindrome(string &s,int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int size = s.size();
        
        // two pointer
        int i = 0, j = size - 1;
        while(i < j){
            if(s[i] == s[j]){
                // both characters are same so move to next 
                i++;
                j--;
            }
            else{
                // characters do not match so 
                // either s[i] is misfit or s[j] is misfit
                // remove each one at a time and check for string
                
                bool removeIthChar = isPalindrome(s,i+1,j);
                bool removeJthChar = isPalindrome(s,i,j-1);
                
                // if any one is true then there is a way to delete one char
                // & make string a palindrome.
                return removeIthChar || removeJthChar;
            }
        }
        // code will reach here only if all characters are fit
        // so string is palindrome no need to delete char
        return true;
    }
};