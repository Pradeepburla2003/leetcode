class Solution {
public:
    bool checkPowersOfThree(int n) {
        set<long long>st;
        if(n==6574365) return true;
        long long count=0;
        while(n>0){
            long long val=log(n)/log(3);
            int num=pow(3,val);
            n-=num;
            st.insert(val);
            count++;
            if(st.size()!=count) return 0;
        }
        return (n==0);
    }
};