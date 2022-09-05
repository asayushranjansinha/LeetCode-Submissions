/* 
    First of all understand the question properly:
*   N is the total number of digits each number could have
*   K is the common difference(absolute) b/w consecutive digits
*   For every place value, we could only have digits 0 - 9 excluding leading 0s.
*   No place can have 10 or more in place of a single digit.
*   The most significant digit can only be b/w 1 to 9

    Approach building
    Since we have a limit of choosing the most significant digit, we will loop from 1 to 9 and try to create as many numbers as possible.
    Now for every place value in a particular number we have certain conditions to obey,
    but we have two choices, 1. add K to previous digit or subtract K from previous digit to have a difference of K. So we try both and whatever suits we add into result array.
*/
class Solution {
private:
    void createNumber(int numberOfDigits, int numberSoFar, int K,
                     vector<int>& result){
        if(numberOfDigits == 0){
            // we have succesfully created a number
            // add to result array
            result.push_back(numberSoFar);
            return;
        }
        // take out last digit till now
        int lastDigit = numberSoFar % 10;
        
        // create a difference of K
        int addcase = lastDigit + K;
        int subcase = lastDigit - K;
        
        // check validity of both cases
        if(addcase <= 9){
            int modifiedNumber = numberSoFar * 10 + addcase;
            createNumber(numberOfDigits-1,modifiedNumber,K,result);
        }        
        if(K > 0 && subcase >= 0){
            int modifiedNumber = numberSoFar * 10 + subcase;
            createNumber(numberOfDigits-1,modifiedNumber,K,result);
        }
    }
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        if(N == 1) result.push_back(0);
        
        // choosing most significant digit
        for(int i = 1; i <= 9; i++){
            int numberOfDigitsLeft = N-1;
            int numberSoFar = i;
            
            createNumber(numberOfDigitsLeft,numberSoFar,K,result);
        }
        return result;
    }
};