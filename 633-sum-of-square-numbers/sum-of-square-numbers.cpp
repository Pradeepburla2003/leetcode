class Solution {
public:
    bool judgeSquareSum(int c) {
        long long n=sqrt(c);
        long long i=0;
        while(i<=n){
            if(((i*i)+(n*n))==c) return true;
            else if(((i*i)+(n*n))>c) n--;
            else i++;
        }
        return false;
    }
};