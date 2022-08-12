class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int low = 0,hi = n-1;
        while(low < hi){
            char a = s[low];
            char b = s[hi];
            s[low] = b;
            s[hi] = a;
            low++;
            hi--;
        }
        return;
    }
};