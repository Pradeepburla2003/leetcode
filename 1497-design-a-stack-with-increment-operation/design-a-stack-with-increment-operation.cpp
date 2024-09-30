class CustomStack {
public:
    deque<int>dq;
    int size = 0;
    stack<int>st;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(dq.size() <= size - 1){
            dq.push_front(x);
        }
    }
    
    int pop() {
        if(dq.empty()) return -1;
        int ele = dq.front();
        dq.pop_front();
        return ele;
    }
    
    void increment(int k, int val) {
        while(!dq.empty() && k){
            st.push(dq.back()+val);
            dq.pop_back();
            k--;
        }
        while(!st.empty()){
            dq.push_back(st.top());
            st.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */