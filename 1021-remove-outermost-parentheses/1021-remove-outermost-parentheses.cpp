class Solution {
private:
    string remove(string str){
        int N = str.size();
        string result = "";
        for(int i = 0; i < N; i++){
            if(i != 0 && i != N - 1){
                result += str[i];
            }
        }
        return result;
    }
public:
    string removeOuterParentheses(string s) {
        int size = s.size();
        string result = "";
        
        int opening = 0,closing = 0;
        string str = "";
        for(auto ch : s){
            str += ch;
            if(ch == ')')closing++;
            else opening++;
            
            if(opening == closing){
                string finalStr = remove(str);
                result += finalStr;
                opening = 0;
                closing = 0;
                str = "";
            }
        }
        return result;
    }
};