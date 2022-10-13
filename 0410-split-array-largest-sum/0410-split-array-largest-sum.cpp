class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // binary search typical question book allocation
        int low = 0;
        int high = 0;
        for(auto num : nums){
            low = max(low,num);
            high += num;
        }
        
        int ans = -1;
        while(low <= high){
            int midSum = (low)+(high - low)/2;
            // decided the largest weight now check is it even possible to do so or not
            
            int count = 1;
            int sum = 0;
            for(auto num : nums){
                sum += num;
                if(sum > midSum){
                    count++;
                    sum = num;
                }
            }
            
            if(count > k){
                // not possible to do so
                // increase sum
                low = midSum+1;
            }
            else{
                // try to minimize the sum
                high = midSum - 1;
                ans = midSum;
            }
        }
        return ans;
    }
};