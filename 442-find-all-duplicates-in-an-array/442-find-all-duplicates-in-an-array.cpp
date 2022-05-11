class Solution {
    void cyclicSort(vector<int> &nums){
        int i = 0,n = nums.size();
        
        while(i < n){
            // element must be at its value - 1 index because [0 to n-1]
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i] - 1]);
            }else{
                i++;
            }
        }
    }
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        cyclicSort(nums);
        // now all elements must be at correct indices
        vector<int> ans;
        for(int index = 0; index < n; index++){
            if(nums[index] != index+1){
                ans.push_back(nums[index]);
            }
        }
        return ans;
    }
};