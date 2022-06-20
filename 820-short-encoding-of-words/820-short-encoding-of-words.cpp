/*
    The problem statement is bullshit.
    In simple words,
        we are given an array storing multiple strings
        we need to generate a string that accomodates all the strings in the input array.
        so first thought would be to concat all strings into resultant string 
        and place # wherever a new string begins.
        but there is a catch,
            if there exists a string (say A) which is coincidently a substring of (say B),
            then we must not add string A in resultant. Just add # after each insertion.

Approach 1: First thought that came into my mind was that all the larger strings will surely be the part of the resultant array. So we sorted the input array based on the length of the strings.
Now we start looping over the input array. When we pushed the string (say str) into the resultant, then we add '#' to resultant, this # indicates the ending of a string.

Now we somehow generate all substrings of str and if we found that any other string in the input array is a substring of str we mark it to not push into resultant.
At last we return length of resultant string.
*/
class Solution {
//     this is how we define our own comparator
    static bool compare(string &a, string &b){
        return a.size()  > b.size();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        int len = 0;
//         step 1: sort the array
        sort(words.begin(),words.end(),compare);
        
//         step 2: push all strings in a hashmap
        unordered_map<string,bool> mp;
        for(auto str : words){
            mp[str] = true;
        }
        
//         step 3: loop over the words array & generate all suffixes
        for(auto str : words){
            int stringSize = str.size();
            if(mp[str] == true){
                len += stringSize + 1;
//                 1 for #
            }
            
//             generate all suffixes & delete from map so that they won't be added
            for(int j = stringSize - 1; j >= 0; j--){
                string s = str.substr(j,stringSize-j);
                if(mp[s] == true){
                    mp[s] = false;
                }
            }
        }
        
        return len;
    }
};