class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        stack<char>stack;
        
        for(auto ch : s){
            if(ch == ')'){
                int size = stack.size();
                depth = max(depth,size);
                stack.pop();
            }else if(ch == '('){
                stack.push(ch);
            }
        }
        return (depth);
    }
};