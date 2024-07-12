class Solution {
public:
    void primes(vector<bool>&seive,int n){
        seive[0]=0,seive[1]=0;
        for(int i=2;i*i<=n;i++){
            if(seive[i]){
                for(int j=i*i;j<=n;j+=i){
                    seive[j]=false;
                }
            }
        }
    }
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<bool>seive(n,true);
        primes(seive,n-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(seive[i]) ans++;
        }
        return ans;
    }
};