class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        int nonZeroIndex = 0;
        
        for(int i = 0; i < N; i++){
            if(nums[i] != 0){
                swap(nums[nonZeroIndex++],nums[i]);
            }
        }
        return;
    }
};