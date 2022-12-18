class Solution {
public:
    bool isPrime(int n) {
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;i++) {
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> factor(int n) {
        vector<int> t;
        for(int i=2;i<=n;i++) {
            while(n%i==0) {
                t.push_back(i);
                n/=i;
            }
        }
        return t;
    }
    int smallestValue(int n) {
        if(isPrime(n)) return n;
        if(n==4) return 4;
        // vector<int> fac = factor(n);
        // for(auto i:fac) cout<<i<<" "; cout<<endl;
        int x = n;
        while(!isPrime(x)) {
            vector<int> fac = factor(x);
            // for(auto i:fac) cout<<i<<" "; cout<<endl;
            int sum = accumulate(fac.begin(),fac.end(),0);
            x = sum;
        }
        // vector<int> fac;
        
        return x;
        
    }
};
