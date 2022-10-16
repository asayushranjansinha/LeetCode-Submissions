class Solution {
public:
    string reverseWords(string s) {
        stack<string>stack;
        string word = "";
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            while(i < s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }
            stack.push(word);
            word = "";
        }
        
        string result = "";
        while(stack.size() > 1){
            word = stack.top();
            stack.pop();
            result += word + " ";
        }
        result += stack.top();
        return result;
    }
};