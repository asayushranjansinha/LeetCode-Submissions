class Solution {
public:
    void moveZeroes(vector<int> &nums){
        int N = nums.size();
        
        int ptr = 0;
        for(int i = 0; i < N; i++){
            if(nums[i] != 0){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
    }
//     brute force
    
//     void moveZeroes(vector<int>& nums) {
//         int N = nums.size();
//         vector<int > temp;
        
//         for(int i = 0; i < N; i++){
//             if(nums[i] != 0){
//                 temp.push_back(nums[i]);
//             }
//         }
        
//         while(N - temp.size()){
//             temp.push_back(0);
//         }
//         nums = temp;
//         return;
//     }
};