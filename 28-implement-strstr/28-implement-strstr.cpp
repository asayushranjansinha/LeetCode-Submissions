class Solution {
    bool checkString(int idx,string s1,string s2){
        // find length of s2
        int len = s2.size();
        string temp = s1.substr(idx,len);
        if(temp == s2){
            return true;
        }else{
            return false;
        }
    }
public:
    int strStr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        
        for(int i = 0; i < n;i++){
            if(checkString(i,s1,s2) == true){
                return i;
            }
        }
        return -1;
    }
};