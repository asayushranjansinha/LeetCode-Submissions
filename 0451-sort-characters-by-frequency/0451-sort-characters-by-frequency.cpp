class Solution {
public:
    string frequencySort(string s) {
        int size = s.size();
        unordered_map<char,int> frequency;
        for(auto ch : s){
            frequency[ch]++;
        }
        
        vector<vector<char>> bucket (size + 1);
        for(auto [ch,frq] : frequency){
            bucket[frq].push_back(ch); // pushing character at index = frequency
        }
        
        string result = "";
        for(int i = size; i >= 0; i--){
            // decreasing frequency
            for(auto ch : bucket[i]){
                result += string(i,ch);
            }
        }
        return result;
    }
};