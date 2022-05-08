/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    // flattened array/vector
    vector<int> output;
    int pointer = 0; // pointing to ith element in output
    
    void flattenList(vector<NestedInteger> &nestedList){
        // we traverse through all elements of the nestedList &
        // determine if it is array or not
        // if found to be another list we recursively call for flattening the list
        // otherwise it is pushed to output
        for(int i = 0; i < nestedList.size(); i++){
            // isInteger is an internal function
            if(nestedList[i].isInteger()){
                // getInteger is an internal function
                output.push_back(nestedList[i].getInteger());
            }
            else{
                // getList is internal function
                flattenList(nestedList[i].getList());
            }
        }
        
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
    }
    
    int next() {
        // print the next value in output array one by one
        int value = output.at(pointer);
        pointer++;
        return value;
    }
    
    bool hasNext() {
        return pointer < output.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */