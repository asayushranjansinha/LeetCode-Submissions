class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int N = nums.size();
        int M = mul.size();
        
        vector<int>nextRow(M+1,0);
        for(int index = M - 1; index >= 0; index--){
            vector<int>currRow(M+1,0);
            for(int left = index; left >= 0; left--){
                int leftSel = nums[left] * mul[index] + nextRow[left+1];
                int rightSel = nums[N - 1 -(index - left)] * mul[index] + nextRow[left];
                currRow[left] = max(leftSel,rightSel);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};