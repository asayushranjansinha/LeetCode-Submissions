class Solution {
public:
    string reverseWords(string s) {
        
        string result = "";
        
        // reverse entire given string 
        reverse(s.begin(),s.end());
        
        // reverse each word and add to result
        string word = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            
            while(i < s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            result += word + ' ';
            word = "";
        }
        int N = result.size();
        result = result.substr(0, N-1);
        return result;
    }
    
};