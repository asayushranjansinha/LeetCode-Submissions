class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int startVal = 1; 
        int endVal = 1e6;
        
        while(startVal <= endVal){
            int divisor = (startVal) + (endVal - startVal)/2;
            
            // divide all nums 
            int result = 0;
            for(auto it : nums){
                result += (it + divisor - 1)/divisor;
            }
            
            if(result > threshold){
                startVal = divisor + 1;
            }
            else{
                endVal = divisor - 1;
            }
        }
        return startVal;
    }
};