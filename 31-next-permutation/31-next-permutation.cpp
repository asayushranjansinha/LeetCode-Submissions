// ps: watch ayushi sharma's video instead of striver
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1){ return; }
        
        
        int index1 = -1; // index to check a[i] < a[i+1] from right to left dir
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index1 = i;
                break;
            }
        }
        
        if(index1 == -1){
            reverse(nums.begin(),nums.end()); 
            return;
            // greatest permutation of a number already present so return smallest value,
            // edge case 
        }
        
        int index2 = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[index1] < nums[i]){
                index2 = i;
                break;
            }
        }
        swap(nums[index1],nums[index2]);
        sort(nums.begin()+index1+1,nums.end());
        return;
    }
};