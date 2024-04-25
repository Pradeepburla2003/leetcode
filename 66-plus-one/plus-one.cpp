class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry;
        int n=digits.size();
        if(digits[n-1]+1<10){
            digits[n-1]+=1;
            return digits;
        }
        carry=1;
        vector<int>ans;
        ans.push_back(0);
        for(int i=n-2;i>=0;i--){
            if(digits[i]+carry==10){
                ans.push_back(0);
                carry=1;
            }
            else{
                ans.push_back(digits[i]+carry);
                carry=0;
            }
        }
        if(carry==1) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};