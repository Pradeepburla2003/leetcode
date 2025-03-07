class Solution {
public:
    bool prime(int num){
        if(num<2) return 0;
        if(num==2) return 1;
        for(int i=2;i<int(sqrt(num))+1;i++){
            if(num%i==0) return 0;
        }
        return 1;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans(2,0);
        int num1=0,num2=0,diff=1e9;
        while(left<=right){
            if(left%2==0 && left!=2){
                left++;
                continue;
            }
            if(prime(left)){
                cout<<left<<" ";
                if(num1==0) num1=left;
                else if(num2==0){
                    if(left-num1<=2) return {num1,left};
                    else if(left-num1<diff){
                        ans[0]=num1;
                        ans[1]=left;
                        diff=left-num1;
                    }
                    // num1=num2;
                    num2=left;
                }
                else{
                    if(left-num2==2) return {num2,left};
                    else if(left-num2<diff){
                        ans[0]=num2;
                        ans[1]=left;
                        diff=left-num2;
                    }
                    num1=num2;
                    num2=left;
                    // cout<<endl<<num1<<" "<<num2<<endl;
                }
            }
            left++;
        }
        if(num1>0 && num2>0) return ans;
        return {-1,-1};
    }
};