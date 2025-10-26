class Bank {
    private:
    vector<long long> bal;
    int n;

    bool valid(int idx){
        return idx > 0 && idx <= n;
    }


public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }
    
    bool transfer(int from, int to, long long money) {
        if(!valid(from) || !valid(to) || bal[from - 1] < money)return false;
        bal[from-1] -= money;
        bal[to - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!valid(account))return false;
        bal[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!valid(account) || bal[account - 1] < money)return false;
        bal[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */