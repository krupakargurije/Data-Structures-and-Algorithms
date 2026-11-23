class ProductOfNumbers {
public:
    vector<int>pref;
    int lastZero;

    ProductOfNumbers(){
        pref.push_back(1);
        lastZero = -1;
    }
    
    void add(int num) {
        if(num == 0){
            // pref.clear(); O(current pref size)
            lastZero = pref.size();
            pref.push_back(1);
        }
        else{
            pref.push_back(pref.back() * num);
        }
    }
    
    int getProduct(int k){
        int n = pref.size();

        if(k >= n || n - k - 1 < lastZero)
            return 0;

        return pref[n-1] / pref[n - k - 1];
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
