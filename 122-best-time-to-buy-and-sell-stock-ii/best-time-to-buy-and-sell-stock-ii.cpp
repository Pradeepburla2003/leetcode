class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int>ans;
        int i=0,n=prices.size(),ans=0;
        while(i<n){
            int mini=prices[i];
            while(i+1<n and prices[i]<prices[i+1]){
                i++;
            }
            ans+=prices[i]-mini;
            i++;
        }
        return ans;
    }
};