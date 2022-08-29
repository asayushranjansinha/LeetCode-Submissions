class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> resultant;
        int N = nums.size();
        
        for(int i = 0; i < N; i++){
            if(nums[i] != 0){
                resultant.push_back(nums[i]);
            }
        }
        for(int i = 0; i < N; i++){
            if(nums[i] == 0){
                resultant.push_back(0);
            }
        }
        nums = resultant;
    }
};