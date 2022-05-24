class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.emplace(-1); // same as st.push() but with no duplication of input
        
        int len = 0,maxLen = 0;
        for(auto i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.emplace(i);
            }else{
                st.pop();
                
                if(st.empty()){
                    // last valid entry removed 
                    // so insert new valid start point
                    st.emplace(i);
                }else{
                    len = i - st.top();
                    maxLen = max(len,maxLen);
                }
            }
        }
        return maxLen;
    }
};