class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        
        for(int i = 0; i < n; i++){
            totalSum += cardPoints[i];
        }
        
        if(k == n){
            return totalSum;
        }
        int windowSize = n-k;
        int previousWindowSum = 0,currentWindowSum = 0,minWindowSum = 0;
        for(int i = 0; i < 0 + windowSize; i++){
            previousWindowSum += cardPoints[i];
        }
        
        minWindowSum = previousWindowSum;
        for(int i = 1; i <= n - windowSize; i++){
            currentWindowSum = previousWindowSum - cardPoints[i-1] + cardPoints[i + windowSize - 1];
            previousWindowSum = currentWindowSum;
            minWindowSum = min(minWindowSum,currentWindowSum);
        }
        cout << minWindowSum << endl;
        return totalSum - minWindowSum;
    }
};