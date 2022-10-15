class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size();
        int midIndex;
        
        while(low < high){
            midIndex = low + (high - low)/2;
            int valueToBePresentAtMid = midIndex;
            int actualValuePresentAtMid = arr[midIndex];
            
            
            if(actualValuePresentAtMid - valueToBePresentAtMid - 1 < k){
                // less values absent so increase index
                low = midIndex + 1;
            }
            else{
                high = midIndex;
            }
        }
        return low + k;
    }
};