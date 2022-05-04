class Solution {
public:
    // optimized approach: dutch national flag algorithm
    void sortColors(vector<int> &nums){
        int N = nums.size();
        int low = 0;
        int hi = N-1;
        int mid = low;
        
        // the logic is that 
        // 0 from 0-index to lo-1
        // 1 from lo-index to mid-1
        // 2 from hi-index to N-1
        
        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }
        return;
    }
    // brute force
//     void sortColors(vector<int>& nums) {
//         int N = nums.size(),z=0,o=0,t=0;
//         for(auto num : nums){
//             if(num == 0){
//                 z++;
//             }else if(num == 1){
//                 o++;
//             }else{
//                 t++;
//             }
//         }
        
//         int i = 0;
//         while(z--){
//             nums[i] = 0;
//             i++;
//         }
//         while(o--){
//             nums[i] = 1;
//             i++;
//         }
//         while(t--){
//             nums[i] = 2;
//             i++;
//         }
//         return;
//     }
};