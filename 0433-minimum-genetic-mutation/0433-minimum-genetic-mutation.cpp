class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>> queue;
        queue.push({start,0});
        
        unordered_set<string> st(bank.begin(),bank.end());
        st.erase(start);
        
        
        while(queue.size() > 0){
            string word = queue.front().first;
            int steps = queue.front().second;
            queue.pop();
            
            if(word == end) return steps;
            
            for(int i = 0; i < word.size(); i++){
                string org = word;
                for(auto ch : "ACGT"){
                    word[i] = ch;
                    
                    
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        queue.push({word,steps+1});
                    }
                }
                word = org;
            }
        }
        return -1;
    }
};