class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n-1;
        int maxWaterCapacity = 0;
        
        while(left != right){
            int minHeight = min(height[left],height[right]);
            int capacity = minHeight * (right - left);
            
            maxWaterCapacity = max(maxWaterCapacity,capacity);
            
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxWaterCapacity;
    }
};