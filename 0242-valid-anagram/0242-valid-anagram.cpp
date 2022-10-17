class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dict1(26,0);
        vector<int> dict2(26,0);
        
        for(auto ch : s){
            int index = ch - 'a';
            dict1[index]++;
        }
        for(auto ch : t){
            int index = ch - 'a';
            dict2[index]++;
        }
        
        for(int i = 0; i < 26; i++){
            if(dict1[i] != dict2[i]) return false;
        }
        return true;       
    }
};