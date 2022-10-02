class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int low = 0, high = N - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            // left part of mid is sorted
            else if(nums[low] <= nums[mid]){
                // search for target in it
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(nums[mid] <= nums[high]){
                // right part is sorted
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};