class Solution {
public:
    string orderlyQueue(string s, int k) {
        string res = s;
        if(k == 1){
            for(int i = 0; i < s.size(); i++){
                //    rotating string by one character at a time
                res = min(s.substr(i) + s.substr(0,i),res);
            }
            return res;
        }
        sort(res.begin(),res.end());
        return res;
    }
};