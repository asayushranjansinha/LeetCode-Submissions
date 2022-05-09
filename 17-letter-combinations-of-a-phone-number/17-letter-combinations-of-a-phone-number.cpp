class Solution {
private:
    vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void fillCombinations(int keyPressed,vector<string> &combi){
        vector<string> copy;
        string options = keypad[keyPressed];
        int n = options.size();
        
        for(int i = 0; i < combi.size(); i++){
            for(int j = 0; j < n; j++){
                copy.push_back(combi[i] + options[j]);
            }
        }
        combi = copy;
    }

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> combi;
        if(!n){
            return combi;
        }
        
        combi.push_back("");
        
        for(int i = 0; i < n; i++){
            int keyPressed = digits[i] - '0';
            fillCombinations(keyPressed,combi);
        }
        return combi;
    }
};