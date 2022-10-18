class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> frequency;
        for(auto ch : s){
            frequency[ch]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto [ch,frq] : frequency){
            pq.push({frq,ch});
        }
        
        string result = "";
        while(pq.empty() == false){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            
            while(freq-->0){
                result += ch;
            }
        }
        return result;
    }
};