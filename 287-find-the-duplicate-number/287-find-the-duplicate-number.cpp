class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // arrange values at index=value positions 
        // Those not in place are duplicate
        
        while(nums[0] != nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
            // place value at 0 index at its correct position
            // there will come a time when all elements will be placed at correct position
            // then nums[0] = x and at x-index value will also be x so, x is the duplicate here
        }
        return nums[0];
    }
};