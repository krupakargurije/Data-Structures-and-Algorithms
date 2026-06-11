class CustomStack {
public:
    stack<int> st, temp;
    int maxSize;
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        // Only push if we haven't reached maximum capacity
        if (st.size() < maxSize) {
            st.push(x);
        }
    }
    
    int pop() {
        if (st.empty()) {
            return -1;
        }
        int num = st.top();
        st.pop();
        return num;
    }
    
    void increment(int k, int val) {
        // 1. Move everything to the temporary stack to access the bottom
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        
        // 2. Move everything back, incrementing the first 'k' elements
        int count = 0;
        while (!temp.empty()) {
            if (count < k) {
                st.push(temp.top() + val);
            } else {
                st.push(temp.top());
            }
            temp.pop();
            count++;
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