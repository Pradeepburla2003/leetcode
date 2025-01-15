class Solution {
public:
    void help(int num,vector<int>&n){
        for(int i=0;i<32;i++){
            if((num>>i)&1) n[31-i]=1;
        }
    }
    int minimizeXor(int num1, int num2) {
        vector<int>n1(32),n2(32),n3(32);
        help(num1,n1);
        help(num2,n2);
        int oneCount=0;
        for(auto i:n2){
            if(i==1) oneCount++;
        }
        for(int i=0;i<32;i++){
            if(n1[i]==1 && oneCount>0){
                n3[i]=1;
                oneCount--;
            }
        }
        for(int i=31;i>=0;i--){
            if(oneCount==0) break;
            if(n1[i]==0){
                n3[i]=1;
                oneCount--;
            }
        }
        int res=0;
        for(int i=31;i>=0;i--){
            if(n3[i]==1) res+=pow(2,31-i);
        }
        return res;
    }
};