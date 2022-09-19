class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        
        if(intervals.size() == 0) return mergedIntervals;
        sort(intervals.begin(),intervals.end());
        
        vector<int> lastPair = intervals[0]; // first pair in intervals 
        
        for(auto it : intervals){
            int currentIntervalStartTime = it[0];
            int currentIntervalEndTime = it[1];
            
            int previousIntervalStartTime = lastPair[0];
            int previousIntervalEndTime = lastPair[1];
            
            // if current start falls between last start and end
            if(currentIntervalStartTime >= previousIntervalStartTime && currentIntervalStartTime <= previousIntervalEndTime){
                // in range so update new end time
                previousIntervalEndTime = max(currentIntervalEndTime,previousIntervalEndTime);
                lastPair[1] = previousIntervalEndTime;
                
            }
            else{
                mergedIntervals.push_back(lastPair);
                lastPair = it; // update last pair with current pair
            }
            
        }
        mergedIntervals.push_back(lastPair);
        return mergedIntervals;
    }
};