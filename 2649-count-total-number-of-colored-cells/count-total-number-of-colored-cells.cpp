class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        long long i=1;
        while(i<n){
            ans+=(4*i);
            i++;
        }
        return ans;
    }
};