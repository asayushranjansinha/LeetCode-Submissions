class Solution {
    bool helper(string s, string t){
        int n = s.size();
        unordered_map<char,char>map;
        
        for(int i = 0; i < n; i++){
            char ch1 = s[i];
            char ch2 = t[i];
            
            if(map.count(ch1)){
                // already mapped
                if(map[ch1] != ch2) return false;
            }
            else{
                map[ch1] = ch2;
            }
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
    }
};