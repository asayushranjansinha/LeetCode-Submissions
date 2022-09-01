class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        int maxSoFar = nums[0];
        int cSum = 0;
        
        for(int i = 0; i < N; i++){
            cSum += nums[i];
            if(cSum > maxSoFar){
                maxSoFar = cSum;
            }
            if(cSum < 0){
                cSum = 0;
            }
        }
        return maxSoFar;
    }
};