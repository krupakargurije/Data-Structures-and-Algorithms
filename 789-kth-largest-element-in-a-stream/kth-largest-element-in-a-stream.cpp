class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else if (num > pq.top()) {
                pq.push(num);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < k)
            pq.push(val);
        else if(pq.top() < val){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */