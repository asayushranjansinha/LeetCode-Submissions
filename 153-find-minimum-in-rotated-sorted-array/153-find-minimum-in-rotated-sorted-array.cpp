class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int low = 0, high = N - 1;
        
        // this can handle edge case of one element in array
        if(nums[low] <= nums[high]){
            return nums[low];
        }
        
        while(low <= high){
            int mid = (low) + (high - low)/2;
            int prev = (mid - 1 + N) % N;
            int next = (mid + 1) % N;
            
            if(nums[mid] < nums[prev]){
                // first element of part 2
                return nums[mid];
            }
            else if(nums[mid] > nums[next]){
                // last element of part 1
                return nums[next];
            }
            else if(nums[low] < nums[mid]){
                // left half is sorted
                low = mid + 1;
            }
            else if(nums[high] > nums[mid]){
                // right half is sorted
                high = mid - 1;
            }
        }
        return -1;
    }
};