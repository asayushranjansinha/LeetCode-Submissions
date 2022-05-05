class MyStack {
    queue<int> q1,q2;
public:
//     Two queue Approach
    MyStack() {
    }
    
    void push(int x) {
        if(q1.empty() == true){
            // first input means no constraints
            q1.push(x);
        }else{
            //removing n-1 elements and pushing into buffer queue
            while(q1.empty() == false){
                q2.push(q1.front());
                q1.pop();
            }
            
            q1.push(x); // pushed val
            
            // place back all n-1 elements
            while(q2.empty() == false){
                q1.push(q2.front());
                q2.pop();
            }
            // now val is at the front
        }
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */