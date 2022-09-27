class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() -1;
        int size = nums.size();
        
        if(size == 1) return 0;
        if(nums[low] > nums[low+1]) return low;
        if(nums[high] > nums[high - 1]) return high;
        
        while(low <= high){
            int mid = (low) + (high - low)/2;
            
            if(mid > 0 && mid < size - 1){
                // non extremities mid
                int curr = nums[mid];
                int prev = nums[mid-1];
                int next = nums[mid+1];
                
                if(curr > prev && curr > next){
                    // peak found
                    return mid;
                }
                else if(next > curr){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else if(mid == 0){
                int curr = nums[mid];
                int next = nums[mid+1];
                if(curr > next){
                    return mid;
                }
                return mid+1;
            }
            else if(mid == size -1){
                int curr = nums[mid];
                int prev = nums[mid-1];
                if(curr > prev){
                    return mid;
                }
                return mid-1;
            }
        }
        return -1;
    }
};