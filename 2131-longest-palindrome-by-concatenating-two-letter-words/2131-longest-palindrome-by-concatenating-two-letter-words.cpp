class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int maxlength = 0;
        
        unordered_map<string,int> map;
        for(auto word: words){
            map[word]++;
        }
        
        bool flag = false;
        for(auto it: map){
            string word = it.first;
            int frequency = it.second;
            
            string reversed = word;
            reverse(reversed.begin(),reversed.end());
            
            if(word == reversed){
                maxlength += frequency / 2;
                if(frequency % 2){
                    flag = true;
                }
            }
            else{
                if(map.count(reversed)){
                    maxlength += min(frequency,map[reversed]);
                    map.erase(reversed);
                }
            }
        }
        maxlength *= 4;
        if(flag){
            maxlength += 2;
        }
        return maxlength;
    }
};