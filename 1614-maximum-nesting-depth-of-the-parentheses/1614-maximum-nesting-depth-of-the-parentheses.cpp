class Solution {
public:
    int maxDepth(string s) {
        int count = 0, maxCount = 0;
        for(auto ch : s){
            if(ch == '('){
                count++;
            } else if(ch == ')'){
                maxCount = max(maxCount,count);
                count--;
            }
        }
        return (maxCount);
    }
};