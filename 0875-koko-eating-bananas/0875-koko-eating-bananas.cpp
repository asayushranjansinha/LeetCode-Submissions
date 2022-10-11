class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = 1e9;
        int ans = INT_MAX;
        while(low <= high){
            int eatingSpeed = (low) + (high - low)/2;
            
            long int timeTaken = 0;
            for(auto it : piles){
                timeTaken += it/eatingSpeed;
                if(it%eatingSpeed != 0) timeTaken+= 1;
            }
            
            if(timeTaken > h){
                // taking more time so increase speed
                low = eatingSpeed + 1;
            }
            else{
                // possible to eat all bananas but let us check at less speed
                high = eatingSpeed - 1;
                ans = min(ans,eatingSpeed);
            }
        }
        return ans;
    }
};