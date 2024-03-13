class Solution {
public:
    int pivotInteger(int n) {
        int i=2,j=n-1,sum1=1,sum2=n;
        if(n==1) return 1;
        while(i<=j){
            if(sum1==sum2 && i==j) return i;
            else if(sum1<sum2){
                sum1+=i;
                i+=1;
            }
            else{
                sum2+=j;
                j-=1;
            }
        }
        return -1;
    }
};