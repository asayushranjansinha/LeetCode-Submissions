class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        int idx = 0;
        
        
        for(int i = 1; i < N; i++){
            if(nums[i] == nums[idx]) continue;
            else{
               nums[++idx] = nums[i]; 
            }
        }
        return idx+1;
    }
};