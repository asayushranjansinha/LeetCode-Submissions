class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int minSteps = 0;
        
        queue<pair<string,int>> que;
        
        // the set is used as a visited array and to get valid words in O(1)
        unordered_set<string> st(wordList.begin(),wordList.end()); // shortcut to push all words in set
        
        st.erase(beginWord); // erase the begin word
        
        // word and steps to reach to that word
        que.push({beginWord,1});
        
        
        while(!que.empty()){
            string word = que.front().first;
            int steps = que.front().second;
            que.pop();
            
            if(word == endWord){
                minSteps = steps;
                break;
            }
            
            for(int i = 0; i < word.size(); i++){
                char originalChar = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        que.push({word,steps+1});
                    }
                }
                word[i] = originalChar;
            }
        }
        return minSteps;
    }
};