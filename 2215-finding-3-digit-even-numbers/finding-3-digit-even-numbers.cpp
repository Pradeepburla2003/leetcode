class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;
        int n = digits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k && digits[i]!=0 && digits[k]%2==0){
                        // int num = 
                        st.insert(digits[i]*100+digits[j]*10+digits[k]);
                    }
                }
            }
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};