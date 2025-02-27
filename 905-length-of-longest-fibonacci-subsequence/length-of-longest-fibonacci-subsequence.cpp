class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>index;
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for(int i=0;i<arr.size();i++){
            index[arr[i]]=i;
        }
        int maxLen=0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                int rem=arr[i]-arr[j];
                if(rem<arr[j] && index.find(rem)!=index.end()){
                    int k=index[rem];
                    dp[j][i]=dp[k][j]+1;
                    maxLen=max(maxLen,dp[j][i]);
                }
                else{
                    dp[j][i]=2;
                }
            }
        }
        return (maxLen>2)?maxLen:0;
    }
};