class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        int digit[10] = {0};
        for(int i=0;i<digits.size();i++) digit[digits[i]]++;
        for(int i=100;i<999;i+=2){
            int h=i/100,t=(i/10)%10,u=i%10;
            digit[h]--;digit[t]--;digit[u]--;
            if(digit[h]>=0 && digit[t]>=0 && digit[u]>=0) ans.push_back(i);
            digit[h]++;digit[t]++;digit[u]++;
        }
        return ans;
    }
};