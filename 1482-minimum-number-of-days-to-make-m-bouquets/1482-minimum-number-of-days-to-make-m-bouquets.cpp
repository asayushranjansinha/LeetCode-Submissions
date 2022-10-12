/* The click is to choose a day when minimum amount of flowers needed are already bloomed, and not to pluck adjacent flowers as they bloom and maintain a record for days required.
So we do binary search for day = 0 to day = INF and find a suitable day when our requirement is fulfilled.
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int startDay = 1, endDay = 1e9;
        
        long long totalFlowersNeeded = (long long) m * k;
        long long gardenSize  = bloomDay.size();
        
        if(gardenSize < totalFlowersNeeded) return -1;
        
        
        int ans = -1;
        while(startDay <= endDay){
            int currDay = (startDay) + (endDay - startDay)/2;
            int flowersPicked = 0;
            int bouquetsMade = 0;
            
            for(auto bloomingDay : bloomDay){
                if(bloomingDay > currDay){
                    // break in adjacent flowers
                    // reset flowers picked till now
                    flowersPicked = 0;
                }
                else                
                    flowersPicked++; // pick one from the garden
                
                if(flowersPicked == k){
                    // desired quantity reached
                    // side the curr bouquet and create new one with zero flowers
                    bouquetsMade++;
                    flowersPicked = 0;                    
                }
                
            }
            
            if(bouquetsMade >= m){
                // answer found now check for less number of days
                ans = currDay;
                endDay = currDay-1;
            }
            else{
                // not enough bouquets made so increment curr day
                startDay = currDay + 1;
            }
        }
        return ans;
    }
};