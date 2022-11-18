class Solution {
public:
    bool isUgly(int n) {
        int factors[3] = {2,3,5};
        
        for(int i = 0; i < 3; i++){
            while(n > 0){
                if(n == 1){
                    return true;
                }
                
                if(n % factors[i] == 0){
                    n = n / factors[i];
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};