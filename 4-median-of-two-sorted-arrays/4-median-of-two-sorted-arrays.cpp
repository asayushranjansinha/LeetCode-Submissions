class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        
        if(N1 > N2) return findMedianSortedArrays(nums2,nums1);
        // we always do binary search on mininum length array to improve time complexity
        
        int start = 0, end = N1;
        // start is start of binary search and end is last element in nums1
        
        while(start <= end){
            int mergedArrayLength = N1 + N2;
            int halfLength = (mergedArrayLength + 1) / 2;
            // just to handle odd even case we add 1
            
            int cut1 = (start + end) /2; 
            // cut 1 partitions nums1 into two parts
            int cut2 = halfLength - cut1;
            
            
            // if left is zero so it means no element in left side of partition, in that case we use infinity
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            
            // if right is N, it means no element on right side of array so consider it as sorted and use infinity
            int right1 = cut1 == N1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == N2 ? INT_MAX : nums2[cut2];
            
            // check if elements are sorted or not
            if(left1 <= right2 && left2 <= right1){
                if(mergedArrayLength % 2 == 0){
                    // even length result after merging
                    // median is (mid1 + mid2 )/2;
                    
                    return (max(left1,left2) + min(right1,right2)) / 2.0;
                }
                // odd length array
                return max(left1,left2);
            }
            else if(left1 > right2){
                // we are too ahead on nums1, move left
                end = cut1 - 1;
            }
            else {
                // we are too behind on nums2, move right
                start = cut1 + 1;
            }
        }
        return 0.0;
    }
};