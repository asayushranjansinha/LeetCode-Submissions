class Solution {
public:
//     optimized approach
    vector<int> numsSameConsecDiff(int n, int k) {
        // most significant digits are fixed from 1 to 9
        vector<int>result = {1,2,3,4,5,6,7,8,9};
        
        // no of digits in each number can be n
        // but we already have selected most significant digits so n - 1
        
        // creating all possible combination, digit by digit
        for(int i = n - 1; i > 0; i--){
            vector<int> tempResult;
            for(auto numberSoFar : result){
                int lastDigit = numberSoFar % 10;
                int addCase = lastDigit + k;
                int subCase = lastDigit - k;
                
                if(addCase <= 9){
                    int modNumber = numberSoFar * 10 + addCase;
                    tempResult.push_back(modNumber);
                }
                if(k > 0 && subCase >= 0){
                    int modNumber = numberSoFar * 10 + subCase;
                    tempResult.push_back(modNumber);
                }
            }
            result = tempResult;
        }
        return result;
    }
};