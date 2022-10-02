class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        if(N == 1){
            return nums[0]; // only element in the array
        }
        
        int low = 0, high = N - 1;
        while(low <= high){
            int mid = (low) + (high - low)/2;
            int prevIndex = (mid - 1 + N) % N;
            int nextIndex = (mid + 1) % N;
            
            if(nums[mid] != nums[prevIndex] && nums[mid] != nums[nextIndex]){
                return nums[mid];
            }
            // mid is the first occ of the two
            else if(nums[mid] == nums[nextIndex]){
                
                // check in left half
                int leftHalfLength = nextIndex - low + 1;
                int rightHalfLength = high - mid + 1;
                if(leftHalfLength % 2 == 1){
                    high = mid - 1;
                }
                else if(rightHalfLength % 2 == 1){
                    low = nextIndex + 1;
                }
            }
            else if(nums[mid] == nums[prevIndex]){
                int leftHalfLength = mid - low + 1;
                int rightHalfLength = high - prevIndex + 1;
                if(leftHalfLength % 2 == 1){
                    high = prevIndex - 1;
                }
                else if(rightHalfLength % 2 == 1){
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};