class Solution {
public:
    int passThePillow(int n, int time) {
        if(n>time) return time+1;
        int k=(2*n)-2;
        int t=time%k;
        // if(t==n) return 2;
        if(t<n) return t+1;
        return 1+k-t;
    }
};