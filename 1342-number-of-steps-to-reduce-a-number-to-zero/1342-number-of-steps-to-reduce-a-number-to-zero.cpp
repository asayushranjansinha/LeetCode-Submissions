class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        if(!num){
            return cnt;
        }
        
        while(num){
            if(num % 2 == 0){
                num /= 2;
            }else{
                num -= 1;
            }
            cnt++;
        }
        return cnt;
    }
};